#ifndef ONII_HASH_DETAIL_BIG_ENDIAN_ADD_BYTES_HPP
#define ONII_HASH_DETAIL_BIG_ENDIAN_ADD_BYTES_HPP

#include <vector>

namespace onii
{
namespace hash
{
namespace detail
{
namespace big_endian
{
template<typename ValueUintT, typename DigestUintT>
void add_bytes(ValueUintT value, std::vector<DigestUintT> &bytes)
{
    for(int32_t i = sizeof(ValueUintT) / sizeof(DigestUintT) - 1; i >= 0; --i)
        bytes.push_back(static_cast<DigestUintT>(value >> (i * sizeof(DigestUintT) * 8)));
}
}
}
}
}

#endif // ONII_HASH_DETAIL_BIG_ENDIAN_ADD_BYTES_HPP
