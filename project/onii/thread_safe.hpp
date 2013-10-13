#ifndef ONII_THREAD_SAFE_HPP
#define ONII_THREAD_SAFE_HPP

#include "detail/thread_safe/mutex.hpp"

#define ONII_THREAD_SAFE  \
    std::lock_guard<onii::detail::thread_safe::mutex_type> onii_thread_safe_lock_guard(onii::detail::thread_safe::mutex);

#define ONII_THREAD_SAFE_BEGIN  \
    {  \
        ONII_THREAD_SAFE

#define ONII_THREAD_SAFE_END  \
    }

#endif // ONII_THREAD_SAFE_HPP
