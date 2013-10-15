#ifndef ONII_HASH_SHA1_HPP
#define ONII_HASH_SHA1_HPP

#include "detail/add_bytes.hpp"
#include "detail/to_uint.hpp"
#include "detail/leftrotate.hpp"
#include "detail/to_string.hpp"

namespace onii
{
namespace hash
{
std::string sha1(std::string const &message)
{
    /*  Thanks http://en.wikipedia.org/wiki/SHA-1
        and http://www.ietf.org/rfc/rfc3174.txt
        and http://www.cs.rit.edu/~bcw5910/482/TeamFlux.pdf */

    // these vars will contain the hash
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    // prepare the message
    std::vector<uint8_t> digest(std::begin(message), std::end(message));
    {
        // find new size
        uint32_t new_size = message.size() + 1;
        while(new_size % (512/8) != 448/8)
            ++new_size;
        digest.resize(new_size);
    }

    // append the '1' bit; most significant bit is "first"
    digest[message.size()] = 0x80;

    // append "0" bits
    for(uint32_t i = message.size() + 1; i < digest.size(); ++i)
        digest[i] = 0;

    // append the size in bits at the end of the buffer
    detail::add_bytes(static_cast<uint64_t>(message.size() * 8), digest);

    // process the message in successive 512-bit chunks:
    for(uint32_t o = 0; o < digest.size(); o += (512/8))
    {
        // break chunk into sixteen 32-bit words w[j], 0 = j = 15
        uint32_t w[80];
        for(uint32_t j = 0; j < 16; ++j)
            w[j] = detail::to_uint<uint32_t>(digest, o + j*4);

        // extend the sixteen 32-bit words into eighty 32-bit words
        for(uint32_t j = 16; j < 80; ++j)
            w[j] = ONII_HASH_DETAIL_LEFTROTATE((w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16]), 1);

        // initialize hash value for this chunk
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;

        // main loop
        uint32_t f, k;
        for(uint32_t i = 0; i < 80; ++i)
        {
            if (i < 20)
            {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            }
            else if (i < 40)
            {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            }
            else if (i < 60)
            {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            }
            else
            {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t tmp = ONII_HASH_DETAIL_LEFTROTATE(a, 5) + f + e + k + w[i];
            e = d;
            d = c;
            c = ONII_HASH_DETAIL_LEFTROTATE(b, 30);
            b = a;
            a = tmp;
        }

        // add this chunk's hash to result
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }

    // cleanup
    digest.clear();

    // get the hash
    detail::add_bytes(h0, digest);
    detail::add_bytes(h1, digest);
    detail::add_bytes(h2, digest);
    detail::add_bytes(h3, digest);
    detail::add_bytes(h4, digest);

    // prepare result
    return detail::to_string(digest);
}
}
}

#endif // ONII_HASH_SHA1_HPP
