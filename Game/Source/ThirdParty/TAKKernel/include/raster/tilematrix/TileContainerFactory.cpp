#include "raster/tilematrix/TileContainerFactory.h"
#include "util/CopyOnWrite.h"
#include "util/IO2.h"
#include "port/STLVectorAdapter.h"
#include <vector>
#include <string>
#include <map>
#include <atomic>
#include "thread/Lock.h"

using namespace TAK::Engine::Util;
using namespace TAK::Engine::Raster::TileMatrix;
using TAK::Engine::Port::String;

//
// TileContainerSpi
//

TileContainerSpi::~TileContainerSpi() NOTHROWS
{}

//
// TileContainerFactory
//

namespace {
    class TileContainerSpiRegistry {
    public:
        typedef std::vector<std::shared_ptr<TileContainerSpi>> SpiVector;
        TAKErr registerSpi(const std::shared_ptr<TileContainerSpi> &spi) NOTHROWS;
        TAKErr unregisterSpi(const TileContainerSpi *spi) NOTHROWS;
        std::pair<SpiVector::const_iterator, SpiVector::const_iterator> iterate() const NOTHROWS;

    private:
        SpiVector spis;
    };

    CopyOnWrite<TileContainerSpiRegistry> &getGlobalTileContainerSpiRegistry();

    struct TileContainerReference
    {
        std::shared_ptr<TileContainer> tileContainer;
        int count = 0;

        TileContainerReference() {}
        TileContainerReference(std::shared_ptr<TileContainer>& container, int c) : tileContainer(container), count(c) {}
    };

    TAK::Engine::Thread::Mutex mutex;
    std::map<std::string, TileContainerReference> pathToTileContainerWrite;
    std::map<std::string, TileContainerReference> pathToTileContainerReadOnly;

    auto mapDeleter = [](const TileContainer* ptr)
    {
        TAK::Engine::Thread::Lock lock(mutex);
        for (std::map<std::string, TileContainerReference>::iterator itw = pathToTileContainerWrite.begin(); itw != pathToTileContainerWrite.end(); ++itw)
        {
            if (itw->second.tileContainer.get() == ptr)
            {
                --itw->second.count;
                if (itw->second.count == 0)
                    pathToTileContainerWrite.erase(itw);
                return;
            }
        }
        for (std::map<std::string, TileContainerReference>::iterator itr = pathToTileContainerReadOnly.begin(); itr != pathToTileContainerReadOnly.end(); ++itr)
        {
            if (itr->second.tileContainer.get() == ptr)
            {
                --itr->second.count;
                if (itr->second.count == 0)
                    pathToTileContainerReadOnly.erase(itr);
                return;
            }
        }
    };
    TAKErr createTileContainer(TileContainerPtr& result, std::shared_ptr<TileContainerSpi> spi, const char* path, const TileMatrix* spec)
    {
        TAK::Engine::Thread::Lock lock(mutex);
        std::shared_ptr<TileContainer> shared;
        auto& tileContainerMap = pathToTileContainerWrite;

        TileContainerPtr res(nullptr, nullptr);
        TAKErr code = spi->create(res, spec->getName(), path, spec);
        TE_CHECKRETURN_CODE(code);

        shared = std::move(res);
        tileContainerMap[std::string(path)] = TileContainerReference(shared, 1 );
        TileContainerPtr ret(shared.get(), mapDeleter);
        result = std::move(ret);
        return TE_Ok;
    }

    TAKErr openTileContainer(TileContainerPtr& result, std::shared_ptr<TileContainerSpi> spi, const char* path, const TileMatrix *spec, bool readOnly)
    {
        TAK::Engine::Thread::Lock lock(mutex);
        std::shared_ptr<TileContainer> shared;

        auto& tileContainerMap = readOnly ? pathToTileContainerReadOnly : pathToTileContainerWrite;
        shared = tileContainerMap[std::string(path)].tileContainer;
        TAKErr code = TE_Ok;
        if (!shared)
        {
            TileContainerPtr res(nullptr, nullptr);
            code = spi->open(res, path, spec, readOnly);
            // Skip logging if spi could not create
            if (code == TE_InvalidArg)
                return code;
            TE_CHECKRETURN_CODE(code);
            if (!res)
                return TE_InvalidArg;
            shared = std::move(res);
            tileContainerMap[std::string(path)] = TileContainerReference(shared, 1);
        }
        else
        {
            tileContainerMap[std::string(path)].count++;
        }
        TileContainerPtr ret(shared.get(), mapDeleter);
        result = std::move(ret);

        return TE_Ok;
    }
}
TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_openOrCreateCompatibleContainer(TileContainerPtr& result, const char* path,
                                                                                             const TileMatrix* spec,
                                                                                             const char* hint) NOTHROWS
{

    if (spec == nullptr)
        return TE_InvalidArg;

    bool exists = false;
    TAKErr code = IO_exists(&exists, path);
    if (code != TE_Ok)
        return code;

    code = TE_InvalidArg;
    bool create = !exists;
    auto iters = getGlobalTileContainerSpiRegistry().read()->iterate();
    while (iters.first != iters.second) {
        std::shared_ptr<TileContainerSpi> spi = *iters.first;
        ++iters.first;
        if (hint != nullptr) {
            int comp = -1;
            code = Port::String_compareIgnoreCase(&comp, spi->getName(), hint);
            TE_CHECKRETURN_CODE(code);
            if (comp != 0)
                continue;
        }

        bool compat = false;
        TAKErr compatCode = spi->isCompatible(&compat, spec);
        TE_CHECKRETURN_CODE(compatCode);

        if (compat) {
            if (create)
                code = createTileContainer(result, spi, path, spec);
            else
            {
                code = openTileContainer(result, spi, path, spec, false);
                if(code != TE_Ok)
                    code = createTileContainer(result, spi, path, spec);
            }
            break;
        }
    }

    return !!result ? code : TE_Unsupported;
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_open(TileContainerPtr& result, const char* path, bool readOnly,
                                                                  const char* hint) NOTHROWS
{

    if (path == nullptr)
        return TE_InvalidArg;

    TAKErr code = TE_InvalidArg;
    auto iters = getGlobalTileContainerSpiRegistry().read()->iterate();
    while (iters.first != iters.second) {
        std::shared_ptr<TileContainerSpi> spi = *iters.first;
        if (hint != nullptr) {
            int comp = -1;
            TAKErr compCode = Port::String_compareIgnoreCase(&comp, spi->getName(), hint);
            TE_CHECKRETURN_CODE(compCode);
            if (comp != 0) {
                ++iters.first;
                continue;
            }
        }

        code = openTileContainer(result, spi, path, nullptr, readOnly);
        if (code != TE_InvalidArg)
            break;
        ++iters.first;
    }

    return code;
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_registerSpi(const std::shared_ptr<TileContainerSpi>& spi) NOTHROWS
{
    return getGlobalTileContainerSpiRegistry().invokeWrite(&TileContainerSpiRegistry::registerSpi, spi);
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_unregisterSpi(const TileContainerSpi* spi) NOTHROWS
{
    return getGlobalTileContainerSpiRegistry().invokeWrite(&TileContainerSpiRegistry::unregisterSpi, spi);
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_visitSpis(Util::TAKErr (*visitor)(void* opaque, TileContainerSpi&),
                                                                       void* opaque) NOTHROWS
{

    if (!visitor)
        return TE_InvalidArg;

    // hold on to shared ptr so instances stay strong while visiting
    std::shared_ptr<const TileContainerSpiRegistry> registry = getGlobalTileContainerSpiRegistry().read();
    
    auto iters = registry->iterate();
    while (iters.first != iters.second) {
        TAKErr visitCode = visitor(opaque, **iters.first);
        if (visitCode == TE_Done)
            return visitCode;
        ++iters.first;
    }
    return TE_Ok;
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_visitCompatibleSpis(Util::TAKErr (*visitor)(void* opaque, TileContainerSpi&),
                                                                                 void* opaque, const TileMatrix* spec) NOTHROWS
{

    if (!visitor)
        return TE_InvalidArg;

    // hold on to shared ptr so instances stay strong while visiting
    std::shared_ptr<const TileContainerSpiRegistry> registry = getGlobalTileContainerSpiRegistry().read();

    auto iters = registry->iterate();
    while (iters.first != iters.second) {
        std::shared_ptr<TileContainerSpi> spi = *iters.first;
        bool compat = false;
        spi->isCompatible(&compat, spec);
        if (compat) {
            TAKErr visitCode = visitor(opaque, **iters.first);
            if (visitCode == TE_Done)
                return visitCode;
        }
        ++iters.first;
    }

    return TE_Ok;
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_visitSpis(Util::TAKErr (*visitor)(void* opaque, TAK::Engine::Port::Collection<std::shared_ptr<TileContainerSpi>>& spis),
                                                                       void* opaque) NOTHROWS
{

    if (!visitor)
        return TE_InvalidArg;

    // hold on to shared ptr so instances stay strong while visiting
    std::shared_ptr<const TileContainerSpiRegistry> registry = getGlobalTileContainerSpiRegistry().read();

    auto iters = registry->iterate();

    std::vector<std::shared_ptr<TileContainerSpi>> spis;
    spis.insert(spis.end(), iters.first, iters.second);
    TAK::Engine::Port::STLVectorAdapter<std::shared_ptr<TileContainerSpi>> adapter(spis);
    return visitor(opaque, adapter);
}

TAKErr TAK::Engine::Raster::TileMatrix::TileContainerFactory_visitCompatibleSpis(Util::TAKErr (*visitor)(void* opaque, TAK::Engine::Port::Collection<std::shared_ptr<TileContainerSpi>>& spis),
                                                                                  void* opaque, const TileMatrix* spec) NOTHROWS
{
    if (!visitor)
        return TE_InvalidArg;

    // hold on to shared ptr so instances stay strong while visiting
    std::shared_ptr<const TileContainerSpiRegistry> registry = getGlobalTileContainerSpiRegistry().read();

    auto iters = registry->iterate();

    std::vector<std::shared_ptr<TileContainerSpi>> spis;
    spis.reserve(std::distance(iters.first, iters.second));

    while (iters.first != iters.second) {
        std::shared_ptr<TileContainerSpi> spi = *iters.first;
        bool compat = false;
        spi->isCompatible(&compat, spec);
        if (compat) {
            spis.push_back(spi);
        }
        ++iters.first;
    }

    TAK::Engine::Port::STLVectorAdapter<std::shared_ptr<TileContainerSpi>> adapter(spis);
    return visitor(opaque, adapter);
}


//
// TileContainerSpiRegistry
//

namespace {
    TAKErr TileContainerSpiRegistry::registerSpi(const std::shared_ptr<TileContainerSpi>& spi) NOTHROWS {
        spis.push_back(spi);
        return TE_Ok;
    }

    TAKErr TileContainerSpiRegistry::unregisterSpi(const TileContainerSpi* spi) NOTHROWS {
        auto it = spis.begin();
        while (it != spis.end()) {
            if ((*it).get() == spi)
                it = spis.erase(it);
            else
                ++it;
        }
        return TE_Ok;
    }

    std::pair<TileContainerSpiRegistry::SpiVector::const_iterator, TileContainerSpiRegistry::SpiVector::const_iterator>
        TileContainerSpiRegistry::iterate() const NOTHROWS {
        return std::make_pair(spis.begin(), spis.end());
    }

    CopyOnWrite<TileContainerSpiRegistry>& getGlobalTileContainerSpiRegistry() {
        static CopyOnWrite<TileContainerSpiRegistry> inst;
        return inst;
    }
}
