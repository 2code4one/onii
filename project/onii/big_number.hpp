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

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
// pre-declaration
class big_int;
namespace big_number
{
template<typename T>
T cast(big_int const&);
}

/////////////////////////////////////////////////
/// @class big_int
/// @brief Represent arbitrary large signed integer
/////////////////////////////////////////////////
class big_int
{
public:

    /////////////////////////////////////////////////
    /// @brief C++ large signed integer
    /////////////////////////////////////////////////
    typedef int64_t  sinteger;

    /////////////////////////////////////////////////
    /// @brief C++ large unsigned integer
    /////////////////////////////////////////////////
    typedef uint64_t uinteger;

    /////////////////////////////////////////////////
    /// @brief zero constant
    /////////////////////////////////////////////////
    static big_int const zero;

    /////////////////////////////////////////////////
    /// @brief one constant
    /////////////////////////////////////////////////
    static big_int const one;

    /////////////////////////////////////////////////
    /// @brief Constructor
    /// @remarks The default value is big_int::zero
    /////////////////////////////////////////////////
    big_int() :
        m_bits(5, 0) // to not call pad_zeros()
    {}

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param number - the hexadecimal number
    /////////////////////////////////////////////////
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

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param number - number to assign
    /// @param positive - is the number positive
    /////////////////////////////////////////////////
    big_int(uinteger number, bool positive) :
        big_int(to_hex_string(number, positive)) // use the string ctor
    {}

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param number - number to assign
    /////////////////////////////////////////////////
    big_int(sinteger number) :
        big_int(std::abs(number), number >= 0) // use the uint ctor
    {}

    /////////////////////////////////////////////////
    /// @brief Assign operator
    ///
    /// @param number - the hexadecimal number
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator=(std::string const &number)
    {
        // copy-swap idiom
        big_int tmp(number);
        std::swap(m_bits, tmp.m_bits);
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Assign operator
    ///
    /// @param number - the number to assign
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator=(sinteger number)
    {
        // copy-swap idiom
        big_int tmp(number);
        std::swap(m_bits, tmp.m_bits);
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Unary plus operator
    ///
    /// @return A copy of *this
    /////////////////////////////////////////////////
    big_int operator+() const
    {
        return big_int(*this);
    }

    /////////////////////////////////////////////////
    /// @brief Unary minus operator
    ///
    /// @return The inverse number
    /////////////////////////////////////////////////
    big_int operator-() const
    {
        // use the two's complement to inverse number
        big_int tmp(*this);
        tmp.flip_compl2();
        return tmp;
    }

    /////////////////////////////////////////////////
    /// @brief Pre-Increment operator
    ///
    /// @return *this
    /////////////////////////////////////////////////
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

    /////////////////////////////////////////////////
    /// @brief Post-Increment operator
    ///
    /// @return A copy of *this before the increment
    /////////////////////////////////////////////////
    big_int operator++(int)
    {
        big_int tmp(*this);
        ++(*this);
        return tmp;
    }

    /////////////////////////////////////////////////
    /// @brief Pre-Decrement operator
    ///
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator--()
    {
        flip_compl2();
        ++(*this);
        flip_compl2();
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Post-Decrement operator
    ///
    /// @return A copy of *this before the decrement
    /////////////////////////////////////////////////
    big_int operator--(int)
    {
        big_int tmp(*this);
        --(*this);
        return tmp;
    }

    /////////////////////////////////////////////////
    /// @brief Addition operator
    ///
    /// @param rhs - the number to add
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator+=(big_int const &rhs)
    {
        // if it's a substration
        big_int sub;
        bool flip = false;
        if(rhs.m_bits[0])
        {
            flip_compl2();
            sub = -rhs;
            flip = true;
        }

        // have the good size
        if(rhs.m_bits.size() > m_bits.size())
            pad_zeros_add(rhs.m_bits.size() - m_bits.size());

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

        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Substraction operator
    ///
    /// @param rhs - the number to sub
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator-=(big_int const &rhs)
    {
        return operator+=(-rhs);
    }

    /////////////////////////////////////////////////
    /// @brief Multiplication operator
    ///
    /// @param rhs - number to multiply by
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator*=(big_int const &rhs)
    {
        // if one number is negative
        bool flip = false;
        if(m_bits[0] ^ rhs.m_bits[0])
            flip = true;

        // current positive value
        big_int tmp(m_bits[0] ? operator-() : *this);

        // multiplication
        operator=(zero);
        for(big_int i; i.less_than(rhs.m_bits[0] ? -rhs : rhs); ++i)
            operator+=(tmp);

        // if it's negative
        if(flip)
            flip_compl2();

        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Division operator
    ///
    /// @param rhs - number to divise by
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator/=(big_int const &rhs)
    {
        if(rhs.equal(zero))
            throw std::domain_error("onii::big_int::operator/= - division by 0");

        // if one number is negative
        bool flip = false;
        if(m_bits[0] ^ rhs.m_bits[0])
            flip = true;

        // current positive value
        if(m_bits[0])
            flip_compl2();

        // division
        big_int i;
        for(; !less_than(rhs.m_bits[0] ? -rhs : rhs); ++i)
            operator+=(rhs.m_bits[0] ? rhs : -rhs);
        operator=(i);

        // if it's negative
        if(flip)
            flip_compl2();

        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Modulo operator
    ///
    /// @param rhs - number to divise by
    /// @return *this
    /////////////////////////////////////////////////
    big_int &operator%=(big_int const &rhs)
    {
        if(rhs.equal(zero))
            throw std::domain_error("onii::big_int::operator%= - modulo 0");

        // if left number is negative
        bool flip = false;
        if(m_bits[0])
            flip = true;

        // current positive value
        if(m_bits[0])
            flip_compl2();

        // division
        big_int i;
        while(!less_than(rhs.m_bits[0] ? -rhs : rhs))
            operator+=(rhs.m_bits[0] ? rhs : -rhs);

        // if it's negative
        if(flip)
            flip_compl2();

        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Bitwise NOT operator
    ///
    /// @return A copy of *this with bits flipped
    /////////////////////////////////////////////////
    big_int operator~() const
    {
        // use the one's complement
        big_int tmp(*this);
        tmp.m_bits.flip();
        return tmp;
    }

    /////////////////////////////////////////////////
    /// @brief Bitwise XOR operator
    ///
    /// @param rhs - right number
    /// @return *this
    /////////////////////////////////////////////////
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

    /////////////////////////////////////////////////
    /// @brief Bitwise AND operator
    ///
    /// @param rhs - right number
    /// @return *this
    /////////////////////////////////////////////////
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

    /////////////////////////////////////////////////
    /// @brief Bitwise OR operator
    ///
    /// @param rhs - right number
    /// @return *this
    /////////////////////////////////////////////////
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

    /////////////////////////////////////////////////
    /// @brief Bitwise LEFT-SHIFT operator
    ///
    /// @param shift - number of shift
    /// @return *this
    /// @remarks Bits are not lost, the sign is not affected
    /////////////////////////////////////////////////
    big_int &operator<<=(big_int const &shift)
    {
        // negative shift
        if(shift.m_bits[0])
            return operator>>=(-shift);

        // negative work the same as positive
        bool flip = false;
        if(m_bits[0])
        {
            flip_compl2();
            flip = true;
        }

        // Add zeros at left
        for(big_int i; i.less_than(shift); ++i)
            m_bits.insert(m_bits.begin() + 1, 0);

        // correct bits representation before returning
        correct_bits();

        // reflip if needed
        if(flip)
            flip_compl2();

        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Bitwise RIGHT-SHIFT operator
    ///
    /// @param shift - number of shift
    /// @return *this
    /// @remarks Bits at right are lost, if there is no more bits: *this == big_int::zero
    /////////////////////////////////////////////////
    big_int &operator>>=(big_int const &shift)
    {
        // negative shift
        if(shift.m_bits[0])
            return operator<<=(-shift);

        // negative work the same as positive
        bool flip = false;
        if(m_bits[0])
        {
            flip_compl2();
            flip = true;
        }

        // Remove bits at left
        for(big_int i; m_bits.size() > 1 && i.less_than(shift); ++i)
            m_bits.erase(m_bits.begin() + 1);

        // no more bit
        if(m_bits.size() == 1)
            m_bits[0] = 0;

        // correct bits representation before returning
        correct_bits();

        // reflip if needed
        if(flip)
            flip_compl2();

        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Check if two number are equal
    ///
    /// @param rhs - right number
    /// @return true if *this and rhs are equal
    /////////////////////////////////////////////////
    bool equal(big_int const &rhs) const
    {
        // use the vector op==
        return m_bits == rhs.m_bits;
    }

    /////////////////////////////////////////////////
    /// @brief Check if two number are less than
    ///
    /// @param rhs - right number
    /// @return true if *this is lesser than rhs
    /////////////////////////////////////////////////
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

    /////////////////////////////////////////////////
    /// @brief Get a hexadecimal string
    ///
    /// @return The number as a hex-string
    /////////////////////////////////////////////////
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
            if(flip && i == static_cast<sinteger>(m_bits.size() - 1) && !b1 && !b2 && !b3 && !b4)
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
            default: break;
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

    // cast to int
    template<typename T>
    T do_cast() const
    {
        // dst type must be an integer
        static_assert(std::is_signed<T>::value || std::is_unsigned<T>::value,
                      "onii::big_number::cast - T must be an integer type");

        // negative number cannot go in unsigned
        if(m_bits[0] && std::is_unsigned<T>::value)
            throw std::underflow_error("onii::big_number::cast - cannot cast a negative number to an unsigned integer");

        // good number of bits ?
        if(std::is_signed<T>::value && 8 * sizeof(T) < m_bits.size())
            throw std::overflow_error("onii::big_number::cast - sizeof(T) is too small");
        else if(std::is_unsigned<T>::value && 8 * sizeof(T) < m_bits.size() - 1)
            throw std::overflow_error("onii::big_number::cast - sizeof(T) is too small");

        // cast
        T tmp = 0;
        big_int sub(*this);
        bool flip = false;
        if(m_bits[0])
        {
            sub.flip_compl2();
            flip = true;
        }
        for(uinteger i = 1; i < sub.m_bits.size(); ++i)
            tmp |= sub.m_bits[i] << (i - 1);
        return flip ? -tmp : tmp;
    }

    /////////////////////////////////////////////////
    /// @cond IGNORE
    // friend function for cast
    template<typename T>
    friend T big_number::cast(big_int const&);
    /// @endcond
    /////////////////////////////////////////////////

    // data members
    std::vector<bool> m_bits; // little-endian, signed (first bit)
};

big_int const big_int::zero = 0x0;
big_int const big_int::one  = 0x1;

/////////////////////////////////////////////////
/// @brief Addition operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs + rhs
/////////////////////////////////////////////////
big_int operator+(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) += rhs;
}

/////////////////////////////////////////////////
/// @brief Substration operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs - rhs
/////////////////////////////////////////////////
big_int operator-(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) -= rhs;
}

/////////////////////////////////////////////////
/// @brief Multiplication operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs * rhs
/////////////////////////////////////////////////
big_int operator*(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) *= rhs;
}

/////////////////////////////////////////////////
/// @brief Division operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs / rhs
/////////////////////////////////////////////////
big_int operator/(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) /= rhs;
}

/////////////////////////////////////////////////
/// @brief Mudulo operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs % rhs
/////////////////////////////////////////////////
big_int operator%(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) %= rhs;
}

/////////////////////////////////////////////////
/// @brief Bitwise XOR operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs ^ rhs
/////////////////////////////////////////////////
big_int operator^(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) ^= rhs;
}

/////////////////////////////////////////////////
/// @brief Bitwise AND operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs & rhs
/////////////////////////////////////////////////
big_int operator&(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) &= rhs;
}

/////////////////////////////////////////////////
/// @brief Bitwise AND operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs | rhs
/////////////////////////////////////////////////
big_int operator|(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) |= rhs;
}

/////////////////////////////////////////////////
/// @brief Bitwise LEFT-SHIFT operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs << rhs
/////////////////////////////////////////////////
big_int operator<<(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) <<= rhs;
}

/////////////////////////////////////////////////
/// @brief Bitwise RIGHT-SHIFT operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return lhs >> rhs
/////////////////////////////////////////////////
big_int operator>>(big_int const &lhs, big_int const &rhs)
{
    return big_int(lhs) >>= rhs;
}

/////////////////////////////////////////////////
/// @brief Equality operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return true if lhs and rhs are equal
/////////////////////////////////////////////////
bool operator==(big_int const &lhs, big_int const &rhs)
{
    return lhs.equal(rhs);
}

/////////////////////////////////////////////////
/// @brief Different operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return true if lhs and rhs are different
/////////////////////////////////////////////////
bool operator!=(big_int const &lhs, big_int const &rhs)
{
    return !(lhs == rhs);
}

/////////////////////////////////////////////////
/// @brief Less than operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return true if lhs is lesser than rhs
/////////////////////////////////////////////////
bool operator<(big_int const &lhs, big_int const &rhs)
{
    return lhs.less_than(rhs);
}

/////////////////////////////////////////////////
/// @brief Greater than operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return true if lhs is greater than rhs
/////////////////////////////////////////////////
bool operator>(big_int const &lhs, big_int const &rhs)
{
    return rhs < lhs;
}

/////////////////////////////////////////////////
/// @brief Less or equal than operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return true if lhs is lesser or equal than rhs
/////////////////////////////////////////////////
bool operator<=(big_int const &lhs, big_int const &rhs)
{
    return !(rhs < lhs);
}

/////////////////////////////////////////////////
/// @brief Greater or equal than operator
///
/// @param lhs - left number
/// @param rhs - right number
/// @return true if lhs is greater or equal than rhs
/////////////////////////////////////////////////
bool operator>=(big_int const &lhs, big_int const &rhs)
{
    return !(lhs < rhs);
}

/////////////////////////////////////////////////
/// @brief Stream output operator
///
/// @param os - the output stream
/// @param rhs - the number
/// @return os
/// @remarks the output number is hexadecimal
/////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &os, big_int const &rhs)
{
    return os << rhs.hex();
}

/////////////////////////////////////////////////
/// @brief Stream input operator
///
/// @param is - the input stream
/// @param rhs - the number
/// @return is
/// @remarks the input number must be hexadecimal
/////////////////////////////////////////////////
std::istream &operator>>(std::istream &is, big_int &rhs)
{
    std::string buf;
    is >> buf;
    rhs = buf;
    return is;
}

/////////////////////////////////////////////////
/// @namespace onii::big_number
/////////////////////////////////////////////////
namespace big_number
{
/////////////////////////////////////////////////
/// @brief Absolute
///
/// @param bi - number
/// @return bi if bi is positive, otherwise return -bi
/////////////////////////////////////////////////
big_int abs(big_int const &bi)
{
    return bi < 0 ? -bi : bi;
}

/////////////////////////////////////////////////
/// @brief Greatest common divisor
///
/// @param a - first number
/// @param b - second number
/// @return the GCD of a and b
/////////////////////////////////////////////////
big_int gcd(big_int const &a, big_int const &b)
{
    // a and b must be positive
    if(a < big_int::zero || b < big_int::zero)
        return gcd(abs(a), abs(b));

    // a must be greater than b
    if(a < b)
        return gcd(b, a);

    // use the Euclidean algorithm
    if(b == big_int::zero)
        return a;
    else
        return gcd(b, a % b);
}

/////////////////////////////////////////////////
/// @brief Lowest common mutiple
///
/// @param a - first number
/// @param b - second number
/// @return the LCM of a and b
/////////////////////////////////////////////////
big_int lcm(big_int const &a, big_int const &b)
{
    // zero case
    if(a == big_int::zero || b == big_int::zero)
        return big_int::zero;

    // use the Euclidean algorithm
    return abs(a * b) / gcd(a, b);
}

/////////////////////////////////////////////////
/// @brief Power
///
/// @param base - the base number
/// @param exp - the exposant
/// @return base pow exp
/// @remarks if exp < 0, return big_int::zero
/////////////////////////////////////////////////
big_int pow(big_int const &base, big_int const &exp)
{
    // zero case
    if(exp == big_int::zero)
        return big_int::one;

    // negative case
    if(exp < 0)
        return big_int::zero;

    // else pow
    big_int tmp = base;
    for(big_int i = big_int::one; i < exp; ++i)
        tmp *= base;
    return tmp;
}

/////////////////////////////////////////////////
/// @brief Cast a big_int into a C++ integer
///
/// @param bi - the number to cast
/// @return bi casted to T
/////////////////////////////////////////////////
template<typename T>
T cast(big_int const &bi)
{
    return bi.do_cast<T>();
}
}
}

#endif // ONII_BIG_NUMBER_HPP
