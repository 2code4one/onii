#ifndef ONII_TO_STRING_HPP
#define ONII_TO_STRING_HPP

/////////////////////////////////////////////////
/// @file onii/to_string.hpp
/////////////////////////////////////////////////

#include <string>

/////////////////////////////////////////////////
/// @cond IGNORE
#define ONII_TO_STRING_SPEC(type)  \
    template<>  \
    std::string to_string<type>(type value)  \
    {  \
        return std::to_string(value);  \
    }
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Convert a NumericT to a string
///
/// @param[in] value - the numeric to convert
/// @return the string
/// @remarks Work only with these types: @code bool, int, long, long long, unsigned long, unsigned long long, float, double, long double, std::string const& @endcode
/// @remarks Boolean values will be converted to "false" and "true"
/////////////////////////////////////////////////
template<typename NumericT>
std::string to_string(NumericT value);

/////////////////////////////////////////////////
/// @cond IGNORE
ONII_TO_STRING_SPEC(int)
ONII_TO_STRING_SPEC(long)
ONII_TO_STRING_SPEC(long long)
ONII_TO_STRING_SPEC(unsigned long)
ONII_TO_STRING_SPEC(unsigned long long)
ONII_TO_STRING_SPEC(float)
ONII_TO_STRING_SPEC(double)
ONII_TO_STRING_SPEC(long double)

template<>
std::string to_string<bool>(bool value)
{
    return value ? "true" : "false";
}

template<>
std::string to_string<std::string const&>(std::string const &value)
{
    return value;
}
/// @endcond
/////////////////////////////////////////////////
}

#undef ONII_TO_STRING_SPEC

#endif // ONII_TO_STRING_HPP
