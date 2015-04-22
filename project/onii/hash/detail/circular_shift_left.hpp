#ifndef ONII_HASH_DETAIL_CIRCULAR_SHIFT_LEFT_HPP
#define ONII_HASH_DETAIL_CIRCULAR_SHIFT_LEFT_HPP

#include <cstdint>

namespace onii
{
namespace hash
{
namespace detail
{
template<typename UintT>
UintT circular_shift_left(UintT word, uint32_t bits)
{
    return ((word << bits) | (word >> ((sizeof(UintT) * 8) - bits)));
}
}
}
}

#endif // ONII_HASH_DETAIL_CIRCULAR_SHIFT_LEFT_HPP
