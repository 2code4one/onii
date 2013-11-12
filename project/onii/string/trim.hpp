#ifndef ONII_STRING_TRIM_HPP
#define ONII_STRING_TRIM_HPP

/////////////////////////////////////////////////
/// @file onii/string/trim.hpp
/////////////////////////////////////////////////

#include <string>
#include <cctype>

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Trim the left of a string
///
/// @param[in] str - the string to trim
/// @return the trimmed string
/////////////////////////////////////////////////
std::string trim_left(std::string const &str)
{
    unsigned int i = 0;
    for(; i < str.size() && std::isspace(str[i]); ++i)
        ;
    return str.substr(i);
}

/////////////////////////////////////////////////
/// @brief Trim the right of a string
///
/// @param[in] str - the string to trim
/// @return the trimmed string
/////////////////////////////////////////////////
std::string trim_right(std::string const &str)
{
    int i = str.size() - 1;
    for(; i >= 0 && std::isspace(str[i]); --i)
        ;
    return str.substr(0, i + 1);
}

/////////////////////////////////////////////////
/// @brief Trim a string
///
/// @param[in] str - the string to trim
/// @return the trimmed string
/////////////////////////////////////////////////
std::string trim(std::string const &str)
{
    return trim_left(trim_right(str));
}
}

#endif // ONII_STRING_TRIM_HPP
