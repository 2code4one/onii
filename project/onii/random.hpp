#ifndef ONII_RANDOM_HPP
#define ONII_RANDOM_HPP

/////////////////////////////////////////////////
/// @file onii/random.hpp
/////////////////////////////////////////////////

#include <ctime>
#include "detail/random/type.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Generate a random number
///
/// @pre T must be an integer or a float type
/// @param min_value - low range for the generation
/// @param max_value - high range for the generation
/// @return The random number between min_value and max_value
/////////////////////////////////////////////////
template<typename T>
T random(T min_value, T max_value)
{
    static typename detail::random::generator<T>::type generator(std::time(nullptr));
    return typename detail::random::distribution<T>::type(min_value, max_value)(generator);
}

/////////////////////////////////////////////////
/// @brief Generate a random number
///
/// @pre T must be an integer or a float type
/// @param max_value - high range for the generation
/// @return The random number between 0 and max_value
/////////////////////////////////////////////////
template<typename T>
T random(T max_value)
{
    return random(detail::random::range_value<T>::min,
                  max_value);
}

/////////////////////////////////////////////////
/// @brief Generate a random number
///
/// @pre T must be an integer or a float type
/// @return The random number
/// @remarks Return between 0 and std::numeric_limits<T>::max() for integer type
/// @remarks Return between 0 and 1 for floating point type
/////////////////////////////////////////////////
template<typename T>
T random()
{
    return random(detail::random::range_value<T>::min,
                  detail::random::range_value<T>::max);
}
}

#endif // ONII_RANDOM_HPP
