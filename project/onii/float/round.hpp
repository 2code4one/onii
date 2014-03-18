#ifndef ONII_FLOAT_ROUND_HPP
#define ONII_FLOAT_ROUND_HPP

/////////////////////////////////////////////////
/// @file onii/float/round.hpp
/////////////////////////////////////////////////

#include <cmath>

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Round a floating point number
///
/// @param[in] number - The floating point number to round
/// @param[in] precision - The rounding precision
/// @return The rounded number
/////////////////////////////////////////////////
template<typename FloatT>
FloatT round(FloatT number, unsigned int precision = 3)
{
    FloatT m = static_cast<FloatT>(1);
    for(unsigned int i = 0; i < precision; ++i)
        m *= static_cast<FloatT>(10);
    return std::floor(number * m + static_cast<FloatT>(0.5)) / m;
}
} // namespace onii

#endif // ONII_FLOAT_ROUND_HPP
