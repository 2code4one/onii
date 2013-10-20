#ifndef ONII_HASH_SHA1_HPP
#define ONII_HASH_SHA1_HPP

#include "detail/big_endian/add_bytes.hpp"
#include "detail/big_endian/to_uint.hpp"
#include "detail/circular_shift.hpp"
#include "detail/to_string.hpp"
#include "detail/ch.hpp"
#include "detail/parity.hpp"
#include "detail/maj.hpp"
#include "do_hash.hpp"

namespace onii
{
namespace hash
{
std::string sha1(std::string const &message)
{
    /*  Thanks http://en.wikipedia.org/wiki/SHA-1
        and http://www.ietf.org/rfc/rfc3174.txt */

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
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xc3d2e1f0;

    // constants defined in SHA-1
    uint32_t k[4] = {0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6};

    // functions
    uint32_t(*f[4])(uint32_t, uint32_t, uint32_t) = {
        detail::ch, detail::parity, detail::maj, detail::parity
    };

    // process the message in successive 512-bits chunks
    for(uint32_t o = 0; o < digest.size(); o += (512/8))
    {
        // break chunk into sixteen 32-bit words w[j]
        uint32_t w[80];
        for(uint32_t j = 0; j < 16; ++j)
            w[j] = detail::big_endian::to_uint<uint32_t>(digest, o + j*4);

        // extend the sixteen 32-bit words into eighty 32-bit words
        for(uint32_t j = 16; j < 80; ++j)
            w[j] = detail::circular_shift(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1);

        // initialize hash value for this chunk
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;

        // main loop
        for(uint32_t i = 0; i < 80; ++i)
        {
            uint32_t tmp = detail::circular_shift(a, 5)
                           + f[i/20](b, c, d)
                           + e
                           + k[i/20]
                           + w[i];
            e = d;
            d = c;
            c = detail::circular_shift(b, 30);
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
    detail::big_endian::add_bytes(h0, digest);
    detail::big_endian::add_bytes(h1, digest);
    detail::big_endian::add_bytes(h2, digest);
    detail::big_endian::add_bytes(h3, digest);
    detail::big_endian::add_bytes(h4, digest);

    // prepare result
    return detail::to_string(digest);
}
}
}

#endif // ONII_HASH_SHA1_HPP
