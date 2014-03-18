#ifndef ONII_FLOAT_EQUAL_HPP
#define ONII_FLOAT_EQUAL_HPP

/////////////////////////////////////////////////
/// @file onii/float/equal.hpp
/////////////////////////////////////////////////

#include <cmath>
#include <limits>

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Compare two floating point values with epsilon
///
/// @param[in] lhs - floating point number
/// @param[in] rhs - floating point number
/// @param[in] ulp - desired precision in ULPs (units in the last place)
/// @return true if lhs and rhs are almost equal
/////////////////////////////////////////////////
template<typename FloatT>
bool equal(FloatT lhs, FloatT rhs, unsigned int ulp = 1)
{
    return std::abs(lhs - rhs) <= std::numeric_limits<FloatT>::epsilon()
                                * std::max(std::abs(lhs), std::abs(rhs))
                                * ulp;
}
} // namespace onii

#endif // ONII_FLOAT_EQUAL_HPP
