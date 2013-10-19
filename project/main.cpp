#include <iostream>
#include "onii/onii.hpp"

template<typename FuncT>
void check(std::string const &msg, std::string const &exp, FuncT F)
{
    std::cout << "\nmessage : '" << msg << "'" << std::endl;
    auto digest = onii::do_hash(msg, F);
    std::cout << "hash    : " << digest << std::endl;
    std::cout << "expected: " << exp << std::endl;
    if(digest != exp) {
        std::cout << "errors  : ";
        for(int i = 0; i < digest.size(); ++i) {
            if(digest[i] != exp[i])
                std::cout << '^';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
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
    check("The quick brown fox jumps over the lazy dog", "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12", onii::hash::sha1);
    check("The quick brown fox jumps over the lazy cog", "de9f2c7fd25e1b3afad3e85a0bd17d9b100db4b3", onii::hash::sha1);

    return 0;
}
