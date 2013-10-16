#ifndef ONII_HASH_DETAIL_ADD_BYTES_HPP
#define ONII_HASH_DETAIL_ADD_BYTES_HPP

#include <vector>

namespace onii
{
namespace hash
{
namespace detail
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

#endif // ONII_HASH_DETAIL_ADD_BYTES_HPP
