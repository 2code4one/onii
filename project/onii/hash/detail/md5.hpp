#ifndef ONII_HASH_DETAIL_MD5_HPP
#define ONII_HASH_DETAIL_MD5_HPP

#include <vector>
#include <cstdint>

// LEFTROTATE function definition
#define ONII_HASH_DETAIL_MD5_LEFTROTATE(x, c)  \
    (((x) << (c)) | ((x) >> (32 - (c))))

namespace onii
{
namespace hash
{
namespace detail
{
namespace md5
{
void add_bytes(uint32_t value, std::vector<uint8_t> &bytes)
{
    bytes.push_back(static_cast<uint8_t>(value));
    bytes.push_back(static_cast<uint8_t>(value >> 8));
    bytes.push_back(static_cast<uint8_t>(value >> 16));
    bytes.push_back(static_cast<uint8_t>(value >> 24));
}

uint32_t to_uint32(std::vector<uint8_t> const &bytes, uint32_t offset)
{
    return static_cast<uint32_t>(bytes[offset])
        | (static_cast<uint32_t>(bytes[offset + 1] << 8))
        | (static_cast<uint32_t>(bytes[offset + 2] << 16))
        | (static_cast<uint32_t>(bytes[offset + 3] << 24));
}
}
}
}
}

#endif // ONII_HASH_DETAIL_MD5_HPP

