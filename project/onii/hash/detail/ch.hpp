#ifndef ONII_HASH_DETAIL_CH_HPP
#define ONII_HASH_DETAIL_CH_HPP

namespace onii
{
namespace hash
{
namespace detail
{
template<typename UintT>
UintT ch(UintT x, UintT y, UintT z)
{
    return ((x & y) ^ ((~x) & z));
}
}
}
}

#endif // ONII_HASH_DETAIL_CH_HPP
