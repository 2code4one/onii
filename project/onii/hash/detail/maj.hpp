#ifndef ONII_HASH_DETAIL_MAJ_HPP
#define ONII_HASH_DETAIL_MAJ_HPP

namespace onii
{
namespace hash
{
namespace detail
{
template<typename UintT>
UintT maj(UintT x, UintT y, UintT z)
{
    return ((x & y) | (x & z) | (y & z));
}
}
}
}

#endif // ONII_HASH_DETAIL_MAJ_HPP
