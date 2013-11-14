#ifndef ONII_BIG_NUMBER_HPP
#define ONII_BIG_NUMBER_HPP

/////////////////////////////////////////////////
/// @file onii/big_number.hpp
/////////////////////////////////////////////////

#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include "string/from_string.hpp"

#include "log.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
// pre-declaration for big_int
class big_real;

class big_int
{
public:

    typedef int64_t  sinteger;
    typedef uint64_t uinteger;

    big_int() :
        m_bits(5, 0) // to not call pad_zeros()
    {}

    big_int(std::string const &number) :
        m_bits(1, 0) // the sign is always allocated
    {
        // check if it's a valid string
        check_string_number(number);

        // loop on each char to insert bits
        for(uinteger i = number[0] == '-' ? 1 : 0; i < number.size(); ++i)
            insert_hex_char(number[i]);

        // if it's a negative number, do the two's complement
        if(number[0] == '-')
            flip_compl2();

        log::debug(hex().c_str()) << bin() << " (" << bin().size() << "b)";
    }

    big_int(sinteger number) :
        big_int(to_hex_string(number)) // use the string ctor
    {}

    big_int(big_real const &number); // defined after the class big_real

    big_int &operator=(std::string const &number)
    {
        // copy-swap idiom
        big_int tmp(number);
        std::swap(m_bits, tmp.m_bits);
        return *this;
    }

    big_int &operator=(sinteger number)
    {
        // copy-swap idiom
        big_int tmp(number);
        std::swap(m_bits, tmp.m_bits);
        return *this;
    }

    big_int &operator=(big_real const &number)
    {
        // copy-swap idiom
        big_int tmp(number);
        std::swap(m_bits, tmp.m_bits);
        return *this;
    }

    big_int operator-() const
    {
        // use the two's complement to inverse number
        big_int tmp(*this);
        tmp.flip_compl2();
        return tmp;
    }

    big_int &operator++()
    {
        // loop begin at right
        uinteger i = m_bits.size() - 1;
        while(true)
        {
            // flip the bit
            m_bits[i].flip();

            // if it's 1, we break
            if(m_bits[i--])
                break;

            // else if it's the last bit at left
            if(i == 0)
            {
                // if it's a negative number, we flip (-1 -> 0)
                if(m_bits[0])
                    m_bits[0].flip();

                // else we add a new bit
                else
                    m_bits.insert(m_bits.begin() + 1, 1);

                // end
                break;
            }
        }

        // correct bits representation before returning
        correct_bits();
        return *this;
    }

    big_int operator++(int)
    {
        big_int tmp(*this);
        ++(*this);
        return tmp;
    }

    big_int &operator--() {}

    big_int operator--(int)
    {
        big_int tmp(*this);
        --(*this);
        return tmp;
    }

    big_int &operator+=(big_int const &rhs) {}
    big_int &operator-=(big_int const &rhs) {}
    big_int &operator*=(big_int const &rhs) {}
    big_int &operator/=(big_int const &rhs) {}
    big_int &operator%=(big_int const &rhs) {}

    big_int &operator~() {}
    big_int &operator^=(big_int const &rhs) {}
    big_int &operator&=(big_int const &rhs) {}
    big_int &operator|=(big_int const &rhs) {}
    big_int &operator<<=(big_int const &rhs) {}
    big_int &operator>>=(big_int const &rhs) {}

    bool equal(big_int const &rhs) const
    {
        // use the vector op==
        return m_bits == rhs.m_bits;
    }

    bool less_than(big_int const &rhs) const {}

    std::string bin() const
    {
        std::string tmp;
        for(uinteger i = 0; i < m_bits.size(); ++i)
            tmp.append(1, m_bits[i] ? '1' : '0');
        return tmp;
    }

    std::string hex() const
    {
        big_int bi;
        bool flip = false;
        std::string tmp;

        // if it's a nagative number
        if(m_bits[0])
        {
            tmp.append(1, '-');

            // we get a prositive number
            bi.m_bits = m_bits;
            bi.flip_compl2();
            flip = true;
        }

        // loop on nimble
        for(uinteger i = 1; i < m_bits.size(); i += 4)
        {
            // get the 4-bits chunck
            bool b1 = flip ? bi.m_bits[i + 0] : m_bits[i + 0];
            bool b2 = flip ? bi.m_bits[i + 1] : m_bits[i + 1];
            bool b3 = flip ? bi.m_bits[i + 2] : m_bits[i + 2];
            bool b4 = flip ? bi.m_bits[i + 3] : m_bits[i + 3];

            // not write '0' for first
            if(flip && i == 1 && !b1 && !b2 && !b3 && !b4)
                continue;

            // write the good hex character
            if     (!b1 && !b2 && !b3 && !b4) tmp.append(1, '0');
            else if(!b1 && !b2 && !b3 &&  b4) tmp.append(1, '1');
            else if(!b1 && !b2 &&  b3 && !b4) tmp.append(1, '2');
            else if(!b1 && !b2 &&  b3 &&  b4) tmp.append(1, '3');
            else if(!b1 &&  b2 && !b3 && !b4) tmp.append(1, '4');
            else if(!b1 &&  b2 && !b3 &&  b4) tmp.append(1, '5');
            else if(!b1 &&  b2 &&  b3 && !b4) tmp.append(1, '6');
            else if(!b1 &&  b2 &&  b3 &&  b4) tmp.append(1, '7');
            else if( b1 && !b2 && !b3 && !b4) tmp.append(1, '8');
            else if( b1 && !b2 && !b3 &&  b4) tmp.append(1, '9');
            else if( b1 && !b2 &&  b3 && !b4) tmp.append(1, 'A');
            else if( b1 && !b2 &&  b3 &&  b4) tmp.append(1, 'B');
            else if( b1 &&  b2 && !b3 && !b4) tmp.append(1, 'C');
            else if( b1 &&  b2 && !b3 &&  b4) tmp.append(1, 'D');
            else if( b1 &&  b2 &&  b3 && !b4) tmp.append(1, 'E');
            else if( b1 &&  b2 &&  b3 &&  b4) tmp.append(1, 'F');
        }

        return tmp;
    }

    std::string dec() const {}

private:

    // check if number is a correct hex integer
    void check_string_number(std::string const &number) const
    {
        // must not be empty
        uinteger s = number.size();
        bool check = s > 0;

        // check each characters
        for(uinteger i = number[0] == '-' ? 1 : 0; check && i < s; ++i)
            check = std::isxdigit(number[i]);

        // throw if error
        if(!check)
            throw std::invalid_argument("big_int: the passed string number is not a valid integer");
    }

    // transform an integer into a hex string
    std::string to_hex_string(sinteger number) const
    {
        std::ostringstream oss;
        std::string neg = number < 0 ? "-" : "";
        oss << std::hex << std::abs(number);
        return neg + oss.str();
    }

    // insert bits from a hex char
    void insert_hex_char(char c)
    {
        switch(std::tolower(c))
        {
            case '0': m_bits.insert(m_bits.end(), {0, 0, 0, 0}); break;
            case '1': m_bits.insert(m_bits.end(), {0, 0, 0, 1}); break;
            case '2': m_bits.insert(m_bits.end(), {0, 0, 1, 0}); break;
            case '3': m_bits.insert(m_bits.end(), {0, 0, 1, 1}); break;
            case '4': m_bits.insert(m_bits.end(), {0, 1, 0, 0}); break;
            case '5': m_bits.insert(m_bits.end(), {0, 1, 0, 1}); break;
            case '6': m_bits.insert(m_bits.end(), {0, 1, 1, 0}); break;
            case '7': m_bits.insert(m_bits.end(), {0, 1, 1, 1}); break;
            case '8': m_bits.insert(m_bits.end(), {1, 0, 0, 0}); break;
            case '9': m_bits.insert(m_bits.end(), {1, 0, 0, 1}); break;
            case 'a': m_bits.insert(m_bits.end(), {1, 0, 1, 0}); break;
            case 'b': m_bits.insert(m_bits.end(), {1, 0, 1, 1}); break;
            case 'c': m_bits.insert(m_bits.end(), {1, 1, 0, 0}); break;
            case 'd': m_bits.insert(m_bits.end(), {1, 1, 0, 1}); break;
            case 'e': m_bits.insert(m_bits.end(), {1, 1, 1, 0}); break;
            case 'f': m_bits.insert(m_bits.end(), {1, 1, 1, 1}); break;
        }
    }

    // correct zeros
    void correct_bits()
    {
        remove_zeros();
        pad_zeros();
    }

    // pad bits with zeros at the left
    void pad_zeros(uinteger mul = 4)
    {
        uinteger diff = (m_bits.size() - 1) % mul;
        if(diff > 0)
            m_bits.insert(m_bits.begin() + 1, mul - diff, 0);
    }

    // remove left zeros
    void remove_zeros()
    {
        if(m_bits.size() > 2)
        {
            if(m_bits[1] == 0)
            {
                m_bits.erase(m_bits.begin() + 1);
                remove_zeros();
            }
        }
    }

    // two's complement
    void flip_compl2()
    {
        // find the first '1' from the right and keep it
        auto it = ++std::find(m_bits.rbegin(), m_bits.rend(), 1);

        // flip all bits at the left
        for(; it != m_bits.rend(); ++it)
            (*it).flip();
    }

    // data members
    std::vector<bool> m_bits; // big-endian, signed
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

big_int operator^(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) ^= rhs;
}

big_int operator&(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) &= rhs;
}

big_int operator|(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) |= rhs;
}

big_int operator<<(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) <<= rhs;
}

big_int operator>>(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) >>= rhs;
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
    return !(rhs < lhs);
}

bool operator>=(big_int const &lhs, big_int const &rhs)
{
    return !(lhs < rhs);
}

std::ostream &operator<<(std::ostream &os, big_int const &rhs)
{
    return os << rhs.hex();
}

std::istream &operator>>(std::istream &is, big_int &rhs)
{
    std::string buf;
    is >> buf;
    rhs = buf;
    return is;
}

namespace big_number
{
big_int pow(big_int const &base, big_int const &exp) {}
big_real pow(big_int const &base, big_real const &exp);
big_real pow(big_real const &base, big_int const &exp);
big_real pow(big_real const &base, big_real const &exp);

big_real root(big_int const &num, big_int const &nth);
big_real root(big_int const &num, big_real const &nth);
big_real root(big_real const &num, big_int const &nth);
big_real root(big_real const &num, big_real const &nth);
}
}

#endif // ONII_BIG_NUMBER_HPP
