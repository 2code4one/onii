#ifndef ONII_HASH_DETAIL_MD5_TO_UINT_HPP
#define ONII_HASH_DETAIL_MD5_TO_UINT_HPP

#include <vector>
#include <cstdint>

namespace onii
{
namespace hash
{
namespace detail
{
namespace md5
{
template<typename UintT, typename DigestUintT>
UintT to_uint(std::vector<DigestUintT> const &bytes, uint32_t index)
{
    UintT r = static_cast<UintT>(bytes[index]);
    for(uint32_t i = 1; i < (sizeof(UintT) / sizeof(DigestUintT)); ++i)
        r |= (static_cast<UintT>(bytes[index + i]) << (i * sizeof(DigestUintT) * 8));
    return r;
}
}
}
}
}

#endif // ONII_HASH_DETAIL_MD5_TO_UINT_HPP
