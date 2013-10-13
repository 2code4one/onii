#ifndef ONII_DETAIL_THREAD_SAFE_MUTEX_HPP
#define ONII_DETAIL_THREAD_SAFE_MUTEX_HPP

#include <mutex>

namespace onii
{
namespace detail
{
namespace thread_safe
{
typedef std::recursive_mutex mutex_type;
mutex_type mutex;
}
}
}

#endif // ONII_DETAIL_THREAD_SAFE_MUTEX_HPP
