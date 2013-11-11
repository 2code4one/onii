#ifndef ONII_FROM_STRING_HPP
#define ONII_FROM_STRING_HPP

/////////////////////////////////////////////////
/// @file onii/from_string.hpp
/////////////////////////////////////////////////

#include <string>

/////////////////////////////////////////////////
/// @cond IGNORE
#define ONII_FROM_STRING_SPEC(type, func)  \
    template<>  \
    type sto<type>(std::string const &str)  \
    {  \
        return func(str);  \
    }
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Convert a string to a NumericT
///
/// @param[in] str - the string to convert
/// @return the numeric value
/// @remarks Work only with these types: @code int, long, long long, unsigned long, unsigned long long, float, double, long double @endcode
/////////////////////////////////////////////////
template<typename NumericT>
NumericT sto(std::string const &str);

/////////////////////////////////////////////////
/// @cond IGNORE
ONII_FROM_STRING_SPEC(int, std::stoi)
ONII_FROM_STRING_SPEC(long, std::stol)
ONII_FROM_STRING_SPEC(long long, std::stoll)
ONII_FROM_STRING_SPEC(unsigned long, std::stoul)
ONII_FROM_STRING_SPEC(unsigned long long, std::stoull)
ONII_FROM_STRING_SPEC(float, std::stof)
ONII_FROM_STRING_SPEC(double, std::stod)
ONII_FROM_STRING_SPEC(long double, std::stold)
/// @endcond
/////////////////////////////////////////////////
}

#undef ONII_FROM_STRING_SPEC

#endif // ONII_FROM_STRING_HPP
