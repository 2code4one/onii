#include <iostream>
#include "onii/onii.hpp"

#include <fstream>

void check(std::string const &msg, std::string const &exp)
{
    std::cout << "message : " << msg << std::endl;
    std::cout << "hash    : " << onii::hash::md5(msg) << std::endl;
    std::cout << "expected: " << exp << std::endl << std::endl;
}

int main()
{
    ONII_THREAD_SAFE_BLOCK
    (
        check("", "d41d8cd98f00b204e9800998ecf8427e");
        check("a", "0cc175b9c0f1b6a831c399e269772661");
        check("abc", "900150983cd24fb0d6963f7d28e17f72");
        check("message digest", "f96b697d7cb7938d525a2f31aaf161d0");
        check("abcdefghijklmnopqrstuvwxyz", "c3fcd3d76192e4007dfb496cca67e13b");
        check("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", "d174ab98d277d9f5a5611c2c9f419d9f");
        check("12345678901234567890123456789012345678901234567890123456789012345678901234567890", "57edf4a22be3c955ac49da2e2107b67a");
    )

    return 0;
}
