#include <iostream>
#include "onii/onii.hpp"

#include <cassert>

int main()
{
    // big number
    {
        onii::big_int uintmax("FFFFFFFFFFFFFFFF");
        assert((++uintmax).hex() == "10000000000000000");
        assert(onii::big_number::pow(2, 64).hex() == "10000000000000000");
        assert((uintmax * 2).hex() == "20000000000000000");
    }

    // cast
    assert(onii::big_number::cast<unsigned int>(0x10) == 16);
    assert(onii::big_number::cast<int>(-0x10) == -16);

    // comparisons
    assert(onii::big_int::zero == onii::big_int::zero);
    assert(onii::big_int::one == onii::big_int::one);
    assert(0 != onii::big_int::one);
    assert(onii::big_int::zero < onii::big_int::one);
    assert(onii::big_int::zero <= onii::big_int::zero);
    assert(onii::big_int::zero <= 1);
    assert(onii::big_int::one > 0);
    assert(onii::big_int::one >= onii::big_int::one);
    assert(1 >= onii::big_int::zero);

    // I/O
    assert(onii::big_int("0").hex() == "0");
    assert(onii::big_int("-F").hex() == "-F");
    assert(onii::big_int("1F78dcA").hex() == "1F78DCA");
    assert(onii::big_int(16).hex() == "10");
    assert(onii::big_int(-16).hex() == "-10");
    assert(onii::big_int(8, false).hex() == "-8");

    // negate
    assert(onii::big_int(-1) == -onii::big_int::one);
    assert(onii::big_int(1) == +onii::big_int::one);

    // increment/decrement
    {
        onii::big_int i;
        assert(i++ == 0);
        assert(i == 1);
        assert(i-- == 1);
        assert(i == 0);
        assert(++i == 1);
        assert(--i == 0);
        assert(--i == -1);
    }

    // arithmetic
    {
        onii::big_int mnine = -9;
        onii::big_int mfour = -4;
        onii::big_int zero = 0;
        onii::big_int two = 2;
        onii::big_int seven = 7;

        // +
        assert(mnine + mfour == -13);
        assert(mnine + two == -7);
        assert(mnine + zero == -9);
        assert(zero + seven == 7);
        assert(seven + two == 9);
        assert(seven + mfour == 3);

        // -
        assert(mnine - mfour == -5);
        assert(mnine - two == -11);
        assert(mnine - zero == -9);
        assert(zero - seven == -7);
        assert(seven - two == 5);
        assert(seven - mfour == 11);

        // *
        assert(mnine * mfour == 36);
        assert(mnine * two == -18);
        assert(mnine * zero == 0);
        assert(zero * seven == 0);
        assert(seven * two == 14);
        assert(seven * mfour == -28);

        // /
        assert(mnine / mfour == 2);
        assert(mnine / two == -4);
        assert(zero / seven == 0);
        assert(seven / two == 3);
        assert(seven / mfour == -1);

        // %
        assert(mnine % mfour == -1);
        assert(mnine % two == -1);
        assert(zero % seven == 0);
        assert(seven % two == 1);
        assert(seven % mfour == 3);
    }

    // bitwise
    {
        onii::big_int one = 1;
        onii::big_int two = 2;
        onii::big_int three = 3;

        // ~
        assert(~one == -2);
        assert(~two == -3);
        assert(~three == -4);

        // ^
        assert((one ^ one) == 0);
        assert((one ^ two) == 3);
        assert((one ^ three) == 2);
        assert((two ^ two) == 0);
        assert((two ^ three) == 1);
        assert((three ^ three) == 0);

        // &
        assert((one & one) == 1);
        assert((one & two) == 0);
        assert((one & three) == 1);
        assert((two & two) == 2);
        assert((two & three) == 2);
        assert((three & three) == 3);

        // |
        assert((one | one) == 1);
        assert((one | two) == 3);
        assert((one | three) == 3);
        assert((two | two) == 2);
        assert((two | three) == 3);
        assert((three | three) == 3);

        // <<
        assert((one << 1) == 2);
        assert((one << three) == 8);
        assert((-one << 1) == -2);
        assert((-one << three) == -8);

        // >>
        assert((two >> 1) == 1);
        assert((two >> three) == 0);
        assert((-two >> 1) == -1);
        assert((-two >> three) == 0);
    }

    // abs
    assert(onii::big_number::abs(1) == 1);
    assert(onii::big_number::abs(-1) == 1);
    assert(onii::big_number::abs(0) == 0);

    // gcd
    assert(onii::big_number::gcd(0, 0) == 0);
    assert(onii::big_number::gcd(0, 1) == 1);
    assert(onii::big_number::gcd(1, 0) == 1);
    assert(onii::big_number::gcd(12, 6) == 6);
    assert(onii::big_number::gcd(12, 9) == 3);
    assert(onii::big_number::gcd(2, -4) == 2);
    assert(onii::big_number::gcd(-2, 4) == 2);
    assert(onii::big_number::gcd(-2, -4) == 2);

    // lcm
    assert(onii::big_number::lcm(0, 0) == 0);
    assert(onii::big_number::lcm(0, 1) == 0);
    assert(onii::big_number::lcm(1, 0) == 0);
    assert(onii::big_number::lcm(12, 6) == 12);
    assert(onii::big_number::lcm(12, 9) == 36);
    assert(onii::big_number::lcm(2, -4) == 4);
    assert(onii::big_number::lcm(-2, 4) == 4);
    assert(onii::big_number::lcm(-2, -4) == 4);

    // pow
    assert(onii::big_number::pow(0, 0) == 1);
    assert(onii::big_number::pow(0, 1) == 0);
    assert(onii::big_number::pow(1, 0) == 1);
    assert(onii::big_number::pow(2, 10) == 1024);
    assert(onii::big_number::pow(12, 2) == 144);
    assert(onii::big_number::pow(2, -4) == 0);
    assert(onii::big_number::pow(-2, 4) == 16);
    assert(onii::big_number::pow(-2, -4) == 0);

    return 0;
}
