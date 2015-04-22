#include <cassert>
#include <iostream>
#include "onii/hash.hpp"

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

    // SHA256 Check
    check("",
          "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
          onii::hash::sha256
    );
    check("The quick brown fox jumps over the lazy dog",
          "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592",
          onii::hash::sha256
    );
    check("The quick brown fox jumps over the lazy dog.",
          "ef537f25c895bfa782526529a9b63d97aa631564d5d789c2b765448c8635fb6c",
          onii::hash::sha256
    );

    // SHA224 Check
    check("",
          "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f",
          onii::hash::sha224
    );
    check("The quick brown fox jumps over the lazy dog",
          "730e109bd7a8a32b1cb9d9a09aa2325d2430587ddbc0c38bad911525",
          onii::hash::sha224
    );
    check("The quick brown fox jumps over the lazy dog.",
          "619cba8e8e05826e9b8c519c0a5c68f4fb653e8a3d8aa04bb2c8cd4c",
          onii::hash::sha224
    );

    // SHA512 Check
    check("",
          "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e",
          onii::hash::sha512
    );
    check("The quick brown fox jumps over the lazy dog",
          "07e547d9586f6a73f73fbac0435ed76951218fb7d0c8d788a309d785436bbb642e93a252a954f23912547d1e8a3b5ed6e1bfd7097821233fa0538f3db854fee6",
          onii::hash::sha512
    );
    check("The quick brown fox jumps over the lazy dog.",
          "91ea1245f20d46ae9a037a989f54f1f790f0a47607eeb8a14d12890cea77a1bbc6c7ed9cf205e67b7f2b8fd4c7dfd3a7a8617e45f3c463d481c7e586c39ac1ed",
          onii::hash::sha512
    );

    return 0;
}
