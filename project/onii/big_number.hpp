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

    static big_int const zero;
    static big_int const one;

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
    }

    big_int(uinteger number, bool positive) :
        big_int(to_hex_string(number, positive)) // use the string ctor
    {}

    big_int(sinteger number) :
        big_int(std::abs(number), number >= 0) // use the uint ctor
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

    big_int operator+() const
    {
        return big_int(*this);
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
        // loop begin at left
        uinteger i = 1;
        while(true)
        {
            // flip the bit
            m_bits[i].flip();

            // if it's 1, we break
            if(m_bits[i++])
                break;

            // out of range
            if(i == m_bits.size())
            {
                // if it's a negative number, we flip (-1 -> 0)
                if(m_bits[0])
                    m_bits[0].flip();

                // else we add a new bit
                else
                    m_bits.push_back(1);

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

    big_int &operator--()
    {
        flip_compl2();
        ++(*this);
        flip_compl2();
        correct_bits();
        return *this;
    }

    big_int operator--(int)
    {
        big_int tmp(*this);
        --(*this);
        return tmp;
    }

    big_int &operator+=(big_int const &rhs)
    {
        // if it's a substration
        big_int sub;
        bool flip = false;
        if(rhs.m_bits[0])
        {
            flip_compl2();
            sub = rhs;
            sub.flip_compl2();
            flip = true;
        }

        // have the good size
        if((flip ? sub.m_bits.size() : rhs.m_bits.size()) > m_bits.size())
            pad_zeros_add((flip ? sub.m_bits.size() : rhs.m_bits.size()) - m_bits.size());

        // loop from left
        bool a, b, r = false;
        for(uinteger i = 1; i < m_bits.size(); ++i)
        {
            a = m_bits[i];
            b = flip ? sub.m_bits[i] : rhs.m_bits[i];
            m_bits[i] = a ^ b ^ r;
            r = a & b || a & r || b & r;
        }

        // rest
        if(m_bits[0] && r)
            m_bits[0] = 0;
        else if(r)
            m_bits.push_back(1);

        // correct bits
        correct_bits();

        // we flip? re-flip
        if(flip)
            flip_compl2();
        else
            correct_bits();

        return *this;
    }

    big_int &operator-=(big_int const &rhs)
    {
        return operator+=(-rhs);
    }

    big_int &operator*=(big_int const &rhs) {}
    big_int &operator/=(big_int const &rhs) {}
    big_int &operator%=(big_int const &rhs) {}

    big_int operator~() const
    {
        // use the one's complement
        big_int tmp(*this);
        tmp.m_bits.flip();
        return tmp;
    }

    big_int &operator^=(big_int const &rhs)
    {
        // have the good size
        if(rhs.m_bits.size() > m_bits.size())
            pad_zeros_add(rhs.m_bits.size() - m_bits.size());

        // xor
        for(uinteger i = 0; i < m_bits.size(); ++i)
            m_bits[i] = !(m_bits[i] == rhs.m_bits[i]);

        // correct bits representation before returning
        correct_bits();
        return *this;
    }

    big_int &operator&=(big_int const &rhs)
    {
        // have the good size
        if(rhs.m_bits.size() > m_bits.size())
            pad_zeros_add(rhs.m_bits.size() - m_bits.size());

        // xor
        for(uinteger i = 0; i < m_bits.size(); ++i)
            m_bits[i] = m_bits[i] && rhs.m_bits[i];

        // correct bits representation before returning
        correct_bits();
        return *this;
    }

    big_int &operator|=(big_int const &rhs)
    {
        // have the good size
        if(rhs.m_bits.size() > m_bits.size())
            pad_zeros_add(rhs.m_bits.size() - m_bits.size());

        // xor
        for(uinteger i = 0; i < m_bits.size(); ++i)
            m_bits[i] = m_bits[i] || rhs.m_bits[i];

        // correct bits representation before returning
        correct_bits();
        return *this;
    }

    big_int &operator<<=(big_int const &shift)
    {
        // Add zeros at left
        for(big_int i; i.less_than(shift); ++i)
            m_bits.insert(m_bits.begin() + 1, 0);

        // correct bits representation before returning
        correct_bits();
        return *this;
    }

    big_int &operator>>=(big_int const &shift)
    {
        // Remove bits at right
        for(big_int i; m_bits.size() > 1 && i.less_than(shift); ++i)
            m_bits.pop_back();

        // no more bit
        if(m_bits.size() == 1)
            m_bits[0] = 0;

        // correct bits representation before returning
        correct_bits();
        return *this;
    }

    bool equal(big_int const &rhs) const
    {
        // use the vector op==
        return m_bits == rhs.m_bits;
    }

    bool less_than(big_int const &rhs) const
    {
        // same sign
        if(m_bits[0] == rhs.m_bits[0])
        {
            // negative
            if(m_bits[0] == 1)
            {
                // more bits -> smaller
                if(m_bits.size() > rhs.m_bits.size())
                    return true;

                // less bits -> bigger
                else if(m_bits.size() < rhs.m_bits.size())
                    return false;
            }

            // positive
            else
            {
                // more bits -> bigger
                if(m_bits.size() > rhs.m_bits.size())
                    return false;

                // less bits -> smaller
                else if(m_bits.size() < rhs.m_bits.size())
                    return true;
            }

            // same number of bits
            for(uinteger i = m_bits.size() - 1; i > 0; --i)
            {
                // first zero is lesser
                if     (m_bits[i] == 1 && rhs.m_bits[i] == 0)
                    return false;
                else if(m_bits[i] == 0 && rhs.m_bits[i] == 1)
                    return true;
            }

            // both are equal
            return false;
        }

        // differents signs
        else
        {
            // *this is negative
            return m_bits[0] == 1;
        }
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

            // we get a positive number
            bi.m_bits = m_bits;
            bi.flip_compl2();
            flip = true;
        }

        // loop on nimble
        for(sinteger i = m_bits.size() - 1; i >= 4; i -= 4)
        {
            // get the 4-bits chunck
            bool b1 = flip ? bi.m_bits[i - 0] : m_bits[i - 0];
            bool b2 = flip ? bi.m_bits[i - 1] : m_bits[i - 1];
            bool b3 = flip ? bi.m_bits[i - 2] : m_bits[i - 2];
            bool b4 = flip ? bi.m_bits[i - 3] : m_bits[i - 3];

            // not write '0' for first
            if(flip && i == m_bits.size() - 1 && !b1 && !b2 && !b3 && !b4)
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

        return tmp + " " + log::container(m_bits);
    }

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
            throw std::invalid_argument("onii::big_int - the passed string number is not a valid integer");
    }

    // transform an integer into a hex string
    std::string to_hex_string(uinteger number, bool positive) const
    {
        std::ostringstream oss;
        std::string neg = !positive ? "-" : "";
        oss << std::hex << number;
        return neg + oss.str();
    }

    // insert bits from a hex char
    void insert_hex_char(char c)
    {
        switch(std::tolower(c))
        {
            case '0': m_bits.insert(m_bits.begin() + 1, {0, 0, 0, 0}); break;
            case '1': m_bits.insert(m_bits.begin() + 1, {1, 0, 0, 0}); break;
            case '2': m_bits.insert(m_bits.begin() + 1, {0, 1, 0, 0}); break;
            case '3': m_bits.insert(m_bits.begin() + 1, {1, 1, 0, 0}); break;
            case '4': m_bits.insert(m_bits.begin() + 1, {0, 0, 1, 0}); break;
            case '5': m_bits.insert(m_bits.begin() + 1, {1, 0, 1, 0}); break;
            case '6': m_bits.insert(m_bits.begin() + 1, {0, 1, 1, 0}); break;
            case '7': m_bits.insert(m_bits.begin() + 1, {1, 1, 1, 0}); break;
            case '8': m_bits.insert(m_bits.begin() + 1, {0, 0, 0, 1}); break;
            case '9': m_bits.insert(m_bits.begin() + 1, {1, 0, 0, 1}); break;
            case 'a': m_bits.insert(m_bits.begin() + 1, {0, 1, 0, 1}); break;
            case 'b': m_bits.insert(m_bits.begin() + 1, {1, 1, 0, 1}); break;
            case 'c': m_bits.insert(m_bits.begin() + 1, {0, 0, 1, 1}); break;
            case 'd': m_bits.insert(m_bits.begin() + 1, {1, 0, 1, 1}); break;
            case 'e': m_bits.insert(m_bits.begin() + 1, {0, 1, 1, 1}); break;
            case 'f': m_bits.insert(m_bits.begin() + 1, {1, 1, 1, 1}); break;
        }
    }

    // correct zeros
    void correct_bits()
    {
        remove_zeros();
        pad_zeros_mul();
    }

    // pad bits with zeros at the right
    void pad_zeros_mul(uinteger mul = 4)
    {
        uinteger diff = (m_bits.size() - 1) % mul;
        if(diff > 0)
            m_bits.insert(m_bits.end(), mul - diff, 0);
    }

    // pad bits with zeros at the right
    void pad_zeros_add(uinteger add)
    {
        m_bits.insert(m_bits.end(), add, 0);
    }

    // remove right zeros
    void remove_zeros()
    {
        if(m_bits.size() > 2)
        {
            if(m_bits.back() == 0)
            {
                m_bits.pop_back();
                remove_zeros();
            }
        }
    }

    // two's complement
    void flip_compl2()
    {
        // find the first '1' from the left and keep it
        auto it = std::find(m_bits.begin() + 1, m_bits.end(), 1);

        // don't forget the sign
        if(it != m_bits.end())
            m_bits[0].flip();
        else
            return;

        // flip all bits at the right
        ++it;
        for(; it != m_bits.end(); ++it)
            (*it).flip();
    }

    // data members
    std::vector<bool> m_bits; // little-endian, signed (first bit)
};

big_int const big_int::zero = 0x0;
big_int const big_int::one  = 0x1;

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
big_int abs(big_int const &bi)
{
    return bi < 0 ? -bi : bi;
}

big_real abs(big_real const &br);

big_int gcd(big_int const &a, big_int const &b) {}
big_int lcm(big_int const &a, big_int const &b) {}

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
