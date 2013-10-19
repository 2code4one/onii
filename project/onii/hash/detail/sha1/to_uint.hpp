#ifndef ONII_HASH_DETAIL_SHA1_TO_UINT_HPP
#define ONII_HASH_DETAIL_SHA1_TO_UINT_HPP

#include <vector>
#include <cstdint>

namespace onii
{
namespace hash
{
namespace detail
{
namespace sha1
{
template<typename UintT, typename DigestUintT>
UintT to_uint(std::vector<DigestUintT> const &bytes, uint32_t index)
{
    UintT r = 0x00000000;
    uint32_t n = sizeof(UintT) / sizeof(DigestUintT);
    for(uint32_t i = 0; i < n; ++i)
        r |= (static_cast<UintT>(bytes[index + i]) << ((n-i-1) * sizeof(DigestUintT) * 8));
    return r;
}
}
}
}
}

#endif // ONII_HASH_DETAIL_SHA1_TO_UINT_HPP
