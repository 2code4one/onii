#ifndef ONII_LOG_HPP
#define ONII_LOG_HPP

#include "detail/log/containers_output.hpp"

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
}
}

#endif // ONII_LOG_HPP
