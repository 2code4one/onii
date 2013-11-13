#ifndef ONII_STRING_FROM_STRING_HPP
#define ONII_STRING_FROM_STRING_HPP

/////////////////////////////////////////////////
/// @file onii/string/from_string.hpp
/////////////////////////////////////////////////

#include <sstream>
#include <string>

/////////////////////////////////////////////////
/// @cond IGNORE
#define ONII_FROM_STRING_SPEC(type, func)  \
    template<>  \
    type from_string<type>(std::string const &str)  \
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
/// @remarks Work for sure with these types: @code bool, int, long, long long, unsigned long, unsigned long long, float, double, long double, std::string @endcode
/// @remarks These boolean values will work: @code 0, [1; infinite[, false, true @endcode
/////////////////////////////////////////////////
template<typename NumericT>
NumericT from_string(std::string const &str)
{
    NumericT ret = NumericT();
    std::istringstream iss(str);
    iss >> ret;
    return ret;
}

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

template<>
bool from_string<bool>(std::string const &str)
{
    if(str.find("false") != std::string::npos)
        return false;
    else if(str.find("true") != std::string::npos)
        return true;
    else
        return from_string<int>(str);
}

template<>
std::string from_string<std::string>(std::string const &str)
{
    return str;
}
/// @endcond
/////////////////////////////////////////////////
}

#undef ONII_FROM_STRING_SPEC

#endif // ONII_STRING_FROM_STRING_HPP
