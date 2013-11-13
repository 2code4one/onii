#ifndef ONII_BIG_NUMBER_INTEGER_HPP
#define ONII_BIG_NUMBER_INTEGER_HPP

/////////////////////////////////////////////////
/// @file onii/big_number/integer.hpp
/////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cmath>

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
class big_int
{
public:

    typedef int64_t sinteger;
    typedef uint64_t uinteger;

    big_int(sinteger number = 0) :
        m_positive(number >= 0),
        m_data(1, std::abs(number))
    {}

    big_int(std::string const &number) {}

    big_int &operator=(sinteger number)
    {
        big_int tmp(number);
        std::swap(m_positive, tmp.m_positive);
        std::swap(m_data, tmp.m_data);
        return *this;
    }

    big_int &operator=(std::string const &number)
    {
        big_int tmp(number);
        std::swap(m_positive, tmp.m_positive);
        std::swap(m_data, tmp.m_data);
        return *this;
    }

    big_int operator+() const
    {
        return big_int(*this);
    }

    big_int operator-() const
    {
        big_int tmp(*this);
        tmp.m_positive = !tmp.m_positive;
        return tmp;
    }

    big_int &operator++() {}
    big_int operator++(int) {}
    big_int &operator--() {}
    big_int operator--(int) {}

    big_int &operator+=(big_int const &rhs) {}
    big_int &operator-=(big_int const &rhs) {}
    big_int &operator*=(big_int const &rhs) {}
    big_int &operator/=(big_int const &rhs) {}
    big_int &operator%=(big_int const &rhs) {}

    bool equal(big_int const &rhs) const
    {
        return m_positive == rhs.m_positive && m_data == rhs.m_data;
    }

    bool less_than(big_int const &rhs) const {}

    std::string to_string() const {}

private:

    bool m_positive;
    std::vector<uinteger> m_data;
    uinteger const base = std::numeric_limits<uinteger>::max();
};

big_int operator+(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) += rhs;
}

big_int operator-(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) -= rhs;
}

big_int operator*(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) *= rhs;
}

big_int operator/(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) /= rhs;
}

big_int operator%(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) %= rhs;
}

bool operator==(big_int const &lhs, big_int const &rhs)
{
    return lhs.equal(rhs);
}

bool operator!=(big_int const &lhs, big_int const &rhs)
{
    return !(lhs == rhs);
}

bool operator<(big_int const &lhs, big_int const &rhs)
{
    return lhs.less_than(rhs);
}

bool operator>(big_int const &lhs, big_int const &rhs)
{
    return rhs < lhs;
}

bool operator<=(big_int const &lhs, big_int const &rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>=(big_int const &lhs, big_int const &rhs)
{
    return rhs <= lhs;
}

std::ostream &operator<<(std::ostream &os, big_int const &rhs)
{
    return os << rhs.to_string();
}

std::istream &operator>>(std::istream &is, big_int &rhs)
{
    std::string buf;
    is >> buf;
    rhs = buf;
    return is;
}
}

#endif // ONII_BIG_NUMBER_INTEGER_HPP
