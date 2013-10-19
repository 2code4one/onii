#ifndef ONII_HASH_DETAIL_PARITY_HPP
#define ONII_HASH_DETAIL_PARITY_HPP

namespace onii
{
namespace hash
{
namespace detail
{
template<typename UintT>
UintT parity(UintT x, UintT y, UintT z)
{
    return (x ^ y ^ z);
}
}
}
}

#endif // ONII_HASH_DETAIL_PARITY_HPP
