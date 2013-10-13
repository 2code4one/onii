#ifndef ONII_LOG_HPP
#define ONII_LOG_HPP

#include "detail/log/containers_output.hpp"
#include "detail/log/logger.hpp"

namespace onii
{
namespace log
{
template<typename ContainerT>
inline std::string container(ContainerT const &c)
{
    return detail::log::containers_output::format_iterator(
        std::begin(c),
        std::end(c)
    );
}

ONII_DETAIL_LOG_DEFINE_LEVEL(0, debug);
ONII_DETAIL_LOG_DEFINE_LEVEL(1, info);
ONII_DETAIL_LOG_DEFINE_LEVEL(2, warning);
ONII_DETAIL_LOG_DEFINE_LEVEL(3, error);
ONII_DETAIL_LOG_DEFINE_LEVEL(4, fatal);
}
}

#endif // ONII_LOG_HPP
