#ifndef TAK_ENGINE_UTIL_BLOCKPOOLALLOCATOR_H_INCLUDED
#define TAK_ENGINE_UTIL_BLOCKPOOLALLOCATOR_H_INCLUDED

#include <cstddef>
#include <memory>

#include "port/Platform.h"
#include "util/Error.h"
#include "util/Memory.h"

namespace TAK {
    namespace Engine {
        namespace Util {
            /**
             * <P>Lifetime of the underlying pool is tied to both the
             * `BlockPoolAllocator` instance and all allocated blocks.
             * Allocated blocks will remain valid even if the
             * `BlockPoolAllocator` is destructed. The pool is only destructed
             * once both the `BlockPoolAllocator` and all outstanding
             * allocated blocks have been destructed.
             *
             * <P>This class is lock-free thread-safe.
             */
            class ENGINE_API BlockPoolAllocator
            {
            public :
                /**
                 * @param blockSize The size of a block, in bytes
                 * @param numBlocks The number of blocks in the pool
                 * @param align     The byte alignment requirement (default to `1`)
                 */
                BlockPoolAllocator(const std::size_t blockSize, const std::size_t numBlocks, const std::size_t align = Port::Platform_max_align()) NOTHROWS;
                ~BlockPoolAllocator() NOTHROWS;
            public :
                /**
                 * Allocates a block from the pool. Lifetime of all returned
                 * blocks is independent of this `BlockPoolAllocator`; blocks
                 * will remain valid until destructed, even if the
                 * `BlockPoolAllocator` has been destructed.
                 * 
                 * @param value                 Returns the block, if allocated
                 * @param heapAllocOnExhaust    If `true`, performs heap
                 *                              allocations if the pool is
                 *                              empty; if `false` will return
                 *                              `TE_OutOfMemory`
                 *
                 * @return  TE_Ok on success, TE_OutOfMemory if allocation
                 *          fails; various codes on failure.
                 */
                TAKErr allocate(std::unique_ptr<void, void(*)(const void *)> &value, const bool heapAllocOnExhaust = true) NOTHROWS;

                /**
                 * Allocates a block from the pool, reinterpreted as the
                 * parameterized type. Callers are responsible for ALL bounds
                 * checking.
                 * 
                 * Lifetime of all returned blocks is independent of this
                 * `BlockPoolAllocator`; blocks will remain valid until
                 * destructed, even if the `BlockPoolAllocator` has been
                 * destructed.
                 * 
                 * @param value                 Returns the block, if allocated
                 * @param heapAllocOnExhaust    If `true`, performs heap
                 *                              allocations if the pool is
                 *                              empty; if `false` will return
                 *                              `TE_OutOfMemory`
                 *
                 * @return  TE_Ok on success, TE_OutOfMemory if allocation
                 *          fails; various codes on failure.
                 */
                template<class T>
                TAKErr allocate(std::unique_ptr<T, void(*)(const T *)> &value, const bool heapAllocOnExhaust = true) NOTHROWS
                {
                    TAKErr code(TE_Ok);
                    std::unique_ptr<void, void(*)(const void*)> block(nullptr, nullptr);
                    code = allocate(block, false);
                    do {
                        if (code == TE_OutOfMemory) {
                            if (!heapAllocOnExhaust)
                                break;
                            value = std::unique_ptr<T, void(*)(const T *)>(reinterpret_cast<T *>(new(std::nothrow) uint8_t[blockSize]), Typed_free_heap<T>);
                            code = !!value ? TE_Ok : TE_OutOfMemory;
                        } else if (code == TE_Ok) {
                            value = std::unique_ptr<T, void(*)(const T *)>(reinterpret_cast<T *>(static_cast<uint8_t *>(block.release())), Typed_free_pool<T>);
                        }
                    } while (false);

                    return !!value ? code : TE_OutOfMemory;
                }
            private :
                template<class T>
                static void Typed_free_pool(const T *typedBlock) NOTHROWS
                {
                    freePoolBlock(static_cast<const void*>(reinterpret_cast<const uint8_t *>(typedBlock)));
                }

                /** Used exclusively for `allocate<T>` */
                template<class T>
                static void Typed_free_heap(const T *typedBlock) NOTHROWS
                {
                    const auto blob = reinterpret_cast<const uint8_t*>(typedBlock);
                    delete[] blob;
                }

                static void freePoolBlock(const void* blockData) NOTHROWS;
            private :
                std::shared_ptr<void> pool;
                std::size_t blockSize;
            };
        }
    }
}

#endif

