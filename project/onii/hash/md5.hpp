#ifndef ONII_HASH_MD5_HPP
#define ONII_HASH_MD5_HPP

#include "detail/add_bytes.hpp"
#include "detail/to_uint.hpp"
#include "detail/circular_shift.hpp"
#include "detail/to_string.hpp"
#include "detail/ch.hpp"
#include "detail/parity.hpp"
#include "do_hash.hpp"

namespace onii
{
namespace hash
{
std::string md5(std::string const &message)
{
    /*  Thanks http://en.wikipedia.org/wiki/MD5
        and http://www.ietf.org/rfc/rfc1321.txt */

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
        digest[i] = 0x00;

    // append the size in bits at the end of the buffer
    detail::add_bytes(static_cast<uint64_t>(message.size() * 8), digest);

    // r specifies the per-round shift amounts
    uint32_t r[64] = {
        7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
        5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
        4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
        6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
    };

    // constants are the integer part of the sines of integers (in radians) * 2^32
    uint32_t k[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    // these vars will contain the hash
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;

    // process the message in successive 512-bit chunks:
    for(uint32_t o = 0; o < digest.size(); o += (512/8))
    {
        // break chunk into sixteen 32-bit words w[j], 0 = j = 15
        uint32_t w[16];
        for(uint32_t j = 0; j < 16; ++j)
            w[j] = detail::to_uint<uint32_t>(digest, o + j*4);

        // initialize hash value for this chunk
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;

        // main loop
        uint32_t f, g;
        for(uint32_t i = 0; i < 64; ++i)
        {
            if (i < 16)
            {
                f = detail::ch(b, c, d);
                g = i;
            }
            else if (i < 32)
            {
                f = detail::ch(d, b, c);
                g = (5*i + 1) % 16;
            }
            else if (i < 48)
            {
                f = detail::parity(b, c, d);
                g = (3*i + 5) % 16;
            }
            else
            {
                f = c ^ (b | (~d));
                g = (7*i) % 16;
            }

            uint32_t tmp = d;
            d = c;
            c = b;
            b = b + detail::circular_shift(a + f + k[i] + w[g], r[i]);
            a = tmp;
        }

        // add this chunk's hash to result
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    // cleanup
    digest.clear();

    // get the hash
    detail::add_bytes(h0, digest);
    detail::add_bytes(h1, digest);
    detail::add_bytes(h2, digest);
    detail::add_bytes(h3, digest);

    // prepare result
    return detail::to_string(digest);
}
}
}

#endif // ONII_HASH_MD5_HPP
