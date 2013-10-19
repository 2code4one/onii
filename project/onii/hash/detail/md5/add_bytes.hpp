#ifndef ONII_HASH_DETAIL_MD5_ADD_BYTES_HPP
#define ONII_HASH_DETAIL_MD5_ADD_BYTES_HPP

#include <vector>

namespace onii
{
namespace hash
{
namespace detail
{
namespace md5
{
template<typename ValueUintT, typename DigestUintT>
void add_bytes(ValueUintT value, std::vector<DigestUintT> &bytes)
{
    for(uint32_t i = 0; i < (sizeof(ValueUintT) / sizeof(DigestUintT)); ++i)
        bytes.push_back(static_cast<DigestUintT>(value >> (i * sizeof(DigestUintT) * 8)));
}
}
}
}
}

#endif // ONII_HASH_DETAIL_MD5_ADD_BYTES_HPP
