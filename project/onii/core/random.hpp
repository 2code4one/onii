#ifndef ONII_CORE_RANDOM_HPP
#define ONII_CORE_RANDOM_HPP

#include "detail/random/type.hpp"

namespace onii
{
namespace core
{
template<typename T>
T random(T min_value, T max_value)
{
    static typename detail::random::generator<T>::type generator;
    return typename detail::random::distribution<T>::type(min_value, max_value)(generator);
}

template<typename T>
T random(T max_value)
{
    return random(detail::random::range_value<T>::min,
                  max_value);
}

template<typename T>
T random()
{
    return random(detail::random::range_value<T>::min,
                  detail::random::range_value<T>::max);
}
}
}

#endif // ONII_CORE_RANDOM_HPP
