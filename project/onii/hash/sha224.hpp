#ifndef ONII_HASH_SHA224_HPP
#define ONII_HASH_SHA224_HPP

/////////////////////////////////////////////////
/// @file onii/hash/sha256.hpp
/////////////////////////////////////////////////

#include "detail/big_endian/add_bytes.hpp"
#include "detail/big_endian/to_uint.hpp"
#include "detail/circular_shift_right.hpp"
#include "detail/to_string.hpp"
#include "detail/ch.hpp"
#include "detail/maj.hpp"
#include "do_hash.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::hash
/////////////////////////////////////////////////
namespace hash
{
/////////////////////////////////////////////////
/// @brief Calculate the SHA-224 hash of a string
///
/// @param[in] message - string to calculate
/// @return The SHA-224 hash
/////////////////////////////////////////////////
std::string sha224(std::string const &message)
{
    /*  Thanks http://en.wikipedia.org/wiki/SHA-2
        and https://tools.ietf.org/html/rfc4634 */

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

    // append the size in 64 bits at the end of the buffer
    detail::big_endian::add_bytes(static_cast<uint64_t>(message.size() * 8), digest);

    // these vars will contain the hash
    uint32_t h0 = 0xc1059ed8;
    uint32_t h1 = 0x367cd507;
    uint32_t h2 = 0x3070dd17;
    uint32_t h3 = 0xf70e5939;
    uint32_t h4 = 0xffc00b31;
    uint32_t h5 = 0x68581511;
    uint32_t h6 = 0x64f98fa7;
    uint32_t h7 = 0xbefa4fa4;

    // constants defined in SHA-256
    uint32_t k[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                      0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                      0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                      0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                      0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                      0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                      0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                      0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                      0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                      0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                      0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                      0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                      0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                      0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                      0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                      0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    // process the message in successive 512-bits chunks
    for(uint32_t o = 0; o < digest.size(); o += (512/8))
    {
        // break chunk into sixteen 32-bit words w[j]
        uint32_t w[64];
        for(uint32_t j = 0; j < 16; ++j)
            w[j] = detail::big_endian::to_uint<uint32_t>(digest, o + j*4);

        // extend the sixteen 32-bit words into sixties 32-bit words
        for(uint32_t j = 16; j < 64; ++j)
        {
            uint32_t s0 = detail::circular_shift_right(w[j-15], 7)
                        ^ detail::circular_shift_right(w[j-15], 18)
                        ^ (w[j-15] >> 3);
            uint32_t s1 = detail::circular_shift_right(w[j-2], 17)
                        ^ detail::circular_shift_right(w[j-2], 19)
                        ^ (w[j-2] >> 10);
            w[j] = w[j-16] + s0 + w[j-7] + s1;
        }

        // initialize hash value for this chunk
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;
        uint32_t f = h5;
        uint32_t g = h6;
        uint32_t h = h7;

        // main loop
        for(uint32_t i = 0; i < 64; ++i)
        {
            uint32_t S0 = detail::circular_shift_right(a, 2)
                        ^ detail::circular_shift_right(a, 13)
                        ^ detail::circular_shift_right(a, 22);
            uint32_t S1 = detail::circular_shift_right(e, 6)
                        ^ detail::circular_shift_right(e, 11)
                        ^ detail::circular_shift_right(e, 25);
            uint32_t T1 = h + S1 + detail::ch(e, f, g) + k[i] + w[i];
            uint32_t T2 = S0 + detail::maj(a, b, c);

            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // add this chunk's hash to result
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    // cleanup
    digest.clear();

    // get the hash
    detail::big_endian::add_bytes(h0, digest);
    detail::big_endian::add_bytes(h1, digest);
    detail::big_endian::add_bytes(h2, digest);
    detail::big_endian::add_bytes(h3, digest);
    detail::big_endian::add_bytes(h4, digest);
    detail::big_endian::add_bytes(h5, digest);
    detail::big_endian::add_bytes(h6, digest);

    // prepare result
    return detail::to_string(digest);
}
}
}


#endif // ONII_HASH_SHA224_HPP
