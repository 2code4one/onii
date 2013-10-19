#ifndef ONII_THREAD_SAFE_HPP
#define ONII_THREAD_SAFE_HPP

/////////////////////////////////////////////////
/// @file onii/thread_safe.hpp
/////////////////////////////////////////////////

#include "detail/thread_safe/mutex.hpp"

/////////////////////////////////////////////////
/// @def ONII_THREAD_SAFE_SCOPE
/// @brief Make a scope thread safe
/////////////////////////////////////////////////
#define ONII_THREAD_SAFE_SCOPE  \
    std::lock_guard<onii::detail::thread_safe::mutex_type> onii_thread_safe_lock_guard(onii::detail::thread_safe::mutex);

/////////////////////////////////////////////////
/// @def ONII_THREAD_SAFE_BLOCK(op)
/// @brief Make instructions between parenthesis thread safe
/////////////////////////////////////////////////
#define ONII_THREAD_SAFE_BLOCK(op)  \
    {  \
        ONII_THREAD_SAFE_SCOPE  \
        op  \
    }

/////////////////////////////////////////////////
/// @def ONII_THREAD_SAFE_LOCK
/// @brief Lock the internal recursive mutex
/////////////////////////////////////////////////
#define ONII_THREAD_SAFE_LOCK  \
    onii::detail::thread_safe::mutex.lock();

/////////////////////////////////////////////////
/// @def ONII_THREAD_SAFE_UNLOCK
/// @brief Unlock the internal recursive mutex
/////////////////////////////////////////////////
#define ONII_THREAD_SAFE_UNLOCK  \
    onii::detail::thread_safe::mutex.unlock();

#endif // ONII_THREAD_SAFE_HPP
