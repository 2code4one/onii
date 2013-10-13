#ifndef ONII_DETAIL_LOG_CONTAINERS_OUTPUT_HPP
#define ONII_DETAIL_LOG_CONTAINERS_OUTPUT_HPP

#include <sstream>
#include <string>
#include <utility> // std::pair

namespace onii
{
namespace detail
{
namespace log
{
namespace containers_output
{
// add a value into the result
template<typename T>
void add_value(T const &value, std::ostringstream &oss)
{
    oss << value;
}

// add a value into the result, for c-string
void add_value(char const *value, std::ostringstream &oss)
{
    oss << '\'' << value << '\'';
}

// add a value into the result, for C++ string
void add_value(std::string const &value, std::ostringstream &oss)
{
    add_value(value.c_str(), oss);
}

// add a value into the result, for std::map-like
template<typename T, typename U>
void add_value(std::pair<T, U> const &value, std::ostringstream &oss)
{
    oss << '(';
    add_value(value.first, oss);
    oss << ", ";
    add_value(value.second, oss);
    oss << ')';
}

// format the iterator and return the result
template<typename InputIterator>
std::string format_iterator(InputIterator first, InputIterator last)
{
    std::ostringstream oss;
    oss << '[';
    for(;;)
    {
        add_value(*first, oss);
        if(++first != last)
            oss << ", ";
        else break;
    }
    oss << ']';
    return oss.str();
}
}
}
}
}

#endif // ONII_DETAIL_LOG_CONTAINERS_OUTPUT_HPP
