#ifndef TAK_ENGINE_THREAD_THREADLOCAL_H_INCLUDED
#define TAK_ENGINE_THREAD_THREADLOCAL_H_INCLUDED

// Should have this on all compilers that support proper C++11 spec
// https://stackoverflow.com/questions/18298280/how-to-declare-a-variable-as-thread-local-portably
#ifndef thread_local
# if __STDC_VERSION__ >= 201112 && !defined __STDC_NO_THREADS__
#  define thread_local _Thread_local
# elif defined _WIN32 && ( \
       defined _MSC_VER || \
       defined __ICL || \
       defined __DMC__ || \
       defined __BORLANDC__ )
#  define thread_local __declspec(thread) 
/* note that ICC (linux) and Clang are covered by __GNUC__ */
# elif defined __GNUC__ || \
       defined __SUNPRO_C || \
       defined __xlC__
#  define thread_local __thread
# else
#  error "Cannot define thread_local"
# endif
#endif

namespace TAK {
    namespace Engine {
        namespace Thread {
            /**
             * A unique static thread local pointer. Must be assigned to object
             * allocated with new as delete is automatically called on assignment
             * change and destruction.
             * 
             * @param T the type
             * @param UniqueTag a unique tag type to ensure the uniqueness of the static pointer (i.e. struct MyTag {}; )
             */
            template <typename T, typename UniqueTag = T>
            class ThreadLocalPtr {
            public:
                // No copy or move
                ThreadLocalPtr(const ThreadLocalPtr&) = delete;
                ThreadLocalPtr(ThreadLocalPtr&&) = delete;
                void operator=(ThreadLocalPtr&&) = delete;
                void operator-(const ThreadLocalPtr&) = delete;

                ThreadLocalPtr() { ptr_ = nullptr; }

                ~ThreadLocalPtr() {
                    if (ptr_)
                        delete ptr_;
                    ptr_ = nullptr;
                }

                operator bool() const { return ptr_ != nullptr; }
                bool operator==(const T* ptr) { return ptr_ == ptr; }
                bool operator!=(const T* ptr) { return ptr_ != ptr; }

                void reset(T* ptr) {
                    this->operator=(ptr);
                }

                ThreadLocalPtr& operator=(T* ptr) {
                    if (ptr_)
                        delete ptr_;
                    ptr_ = ptr;
                    return *this;
                }

                T& operator*() const { return *ptr_; }
                T* operator->() const { return ptr_; }

            private:
                static thread_local T* ptr_;
            };

            template <typename T, typename UniqueTag>
            thread_local T* ThreadLocalPtr<T, UniqueTag>::ptr_ = nullptr;
        }
    }
}

#endif