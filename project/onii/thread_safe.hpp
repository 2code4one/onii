#ifndef ONII_THREAD_SAFE_HPP
#define ONII_THREAD_SAFE_HPP

#include "detail/thread_safe/mutex.hpp"

#define ONII_THREAD_SAFE_SCOPE  \
    std::lock_guard<onii::detail::thread_safe::mutex_type> onii_thread_safe_lock_guard(onii::detail::thread_safe::mutex);

#define ONII_THREAD_SAFE_BLOCK(op)  \
    {  \
        ONII_THREAD_SAFE_SCOPE  \
        op  \
    }

#define ONII_THREAD_SAFE_LOCK  \
    onii::detail::thread_safe::mutex.lock();

#define ONII_THREAD_SAFE_UNLOCK  \
    onii::detail::thread_safe::mutex.unlock();

#endif // ONII_THREAD_SAFE_HPP
