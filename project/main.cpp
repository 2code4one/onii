#include <iostream>
#include "onii/onii.hpp"

#include <fstream>

template<typename FuncT>
void check(std::string const &msg, std::string const &exp, FuncT F)
{
    std::cout << "message : " << msg << std::endl;
    std::cout << "hash    : " << onii::do_hash(msg, F) << std::endl;
    std::cout << "expected: " << exp << std::endl << std::endl;
}

int main()
{
    // MD5 Check
    check("", "d41d8cd98f00b204e9800998ecf8427e", onii::hash::md5);
    check("a", "0cc175b9c0f1b6a831c399e269772661", onii::hash::md5);
    check("abc", "900150983cd24fb0d6963f7d28e17f72", onii::hash::md5);
    check("message digest", "f96b697d7cb7938d525a2f31aaf161d0", onii::hash::md5);
    check("abcdefghijklmnopqrstuvwxyz", "c3fcd3d76192e4007dfb496cca67e13b", onii::hash::md5);
    check("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", "d174ab98d277d9f5a5611c2c9f419d9f", onii::hash::md5);
    check("12345678901234567890123456789012345678901234567890123456789012345678901234567890", "57edf4a22be3c955ac49da2e2107b67a", onii::hash::md5);

    // SHA1 Check
    check("", "da39a3ee5e6b4b0d3255bfef95601890afd80709", onii::hash::sha1);
//    check("abcd", "81fe8bfe87576c3ecb22426f8e57847382917acf", onii::hash::sha1);
//    check("abcdefghijklmnopqrstuvwxyz", "32d10c7b8cf96570ca04ce37f2a19d84240d3a89", onii::hash::sha1);
//    check("The Quick Brown Fox Jumps Over The Lazy Dog", "645218467886dd414ea66a09b6cceea806127fb5", onii::hash::sha1);
//    check("The quick brown fox jumps over the lazy dog", "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12", onii::hash::sha1);

    return 0;
}
