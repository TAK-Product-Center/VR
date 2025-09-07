#include "Tileset.h"

#include "TakPrepareRendererResources.h"
#include "TakTaskProcessor.h"

#include "Cesium3DTilesContent/registerAllTileContentTypes.h"
#include "CesiumUtility/Uri.h"
#include "spdlog/sinks/base_sink.h"

using namespace TAK::Engine::Util;

namespace
{
    bool init()
    {
        Cesium3DTilesContent::registerAllTileContentTypes();
        return true;
    }

    template<typename Mutex>
    class tak_sink : public spdlog::sinks::base_sink<Mutex>
    {
    protected:
        void sink_it_(const spdlog::details::log_msg &msg) override
        {
            // log_msg is a struct containing the log entry info like level, timestamp, thread id etc.
            // msg.payload (before v1.3.0: msg.raw) contains pre formatted log

            // If needed (very likely but not mandatory), the sink formats the message before sending it to its final destination:
            spdlog::memory_buf_t formatted;
            spdlog::sinks::base_sink<Mutex>::formatter_->format(msg, formatted);
            LogLevel lvl;
            switch(msg.level)
            {
                case spdlog::level::err: lvl = LogLevel::TELL_Error;
                case spdlog::level::critical: lvl = LogLevel::TELL_Severe;
                case spdlog::level::warn: lvl = LogLevel::TELL_Warning;
                case spdlog::level::debug: lvl = LogLevel::TELL_Debug;
                case spdlog::level::info:
                case spdlog::level::trace:
                case spdlog::level::n_levels: lvl = LogLevel::TELL_Info;
                case spdlog::level::off: lvl = LogLevel::TELL_None;
            }
            Logger_log(lvl, fmt::to_string(formatted).c_str());
        }

        void flush_() override
        {
        }
    };
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tileset_create(TilesetPtr &result, const char* uri, std::shared_ptr<CesiumAsync::IAssetAccessor> &assetAccessor, const TilesetOpenOptions& opts) NOTHROWS
{
    static bool inited = init();

    std::unique_ptr<Cesium3DTilesSelection::IPrepareRendererResources> pPrepareRendererResource(new TakPrepareRendererResources());
    std::unique_ptr<CesiumUtility::CreditSystem> pCreditSystem(new CesiumUtility::CreditSystem());

    CesiumAsync::AsyncSystem asyncSystem{std::unique_ptr<CesiumAsync::ITaskProcessor>(new TakTaskProcessor())};

    auto sink = std::make_shared<tak_sink<std::mutex>>();
    auto logger = std::make_unique<spdlog::logger>("taklogger", sink);
    Cesium3DTilesSelection::TilesetExternals externals{
            assetAccessor,
            std::move(pPrepareRendererResource),
            std::move(asyncSystem),
            std::move(pCreditSystem),
            std::move(logger)};
    Cesium3DTilesSelection::TilesetOptions options = Cesium3DTilesSelection::TilesetOptions();
    options.maximumScreenSpaceError = opts.maximumScreenSpaceError;
    result = TilesetPtr(new Cesium3DTilesSelection::Tileset(externals, uri, options), Memory_leaker<const Cesium3DTilesSelection::Tileset>);
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tileset_updateView(std::unique_ptr<const Cesium3DTilesSelection::ViewUpdateResult> &result,
                                                               Cesium3DTilesSelection::Tileset& tileset,
                                                               double positionx, double positiony, double positionz,
                                                               double directionx, double directiony, double directionz,
                                                               double upx, double upy, double upz,
                                                               double viewportSizex, double viewportSizey,
                                                               double hfov, double vfov) NOTHROWS
{
    std::vector<Cesium3DTilesSelection::ViewState> frustums;
    auto viewState = Cesium3DTilesSelection::ViewState::create(glm::dvec3(positionx, positiony, positionz),
                                                               glm::normalize(glm::dvec3(directionx, directiony, directionz)),
                                                               glm::normalize(glm::dvec3(upx, upy, upz)),
                                                               glm::dvec2(viewportSizex, viewportSizey),
                                                               hfov, vfov);
    frustums.push_back(viewState);
    result = std::make_unique<const Cesium3DTilesSelection::ViewUpdateResult>(tileset.updateView(frustums, 1.0));
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tileset_loadRootTileSync(Cesium3DTilesSelection::Tileset& tileset) NOTHROWS
{
    tileset.getRootTileAvailableEvent().waitInMainThread();
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tileset_getRootTile(const Cesium3DTilesSelection::Tile** tile, const Cesium3DTilesSelection::Tileset& tileset) NOTHROWS
{
    *tile = tileset.getRootTile();
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tileset_destroy(Cesium3DTilesSelection::Tileset* tileset) NOTHROWS
{
    delete tileset;
    return TE_Ok;
}
