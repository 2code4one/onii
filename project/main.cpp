#include <cassert>
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

    return 0;
}
