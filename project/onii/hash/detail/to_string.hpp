#ifndef ONII_HASH_DETAIL_TO_STRING_HPP
#define ONII_HASH_DETAIL_TO_STRING_HPP

#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdint>

namespace onii
{
namespace hash
{
namespace detail
{
template<typename UintT> struct to_string_bit_size;
template<> struct to_string_bit_size<uint8_t> { static constexpr int width = 2; };
template<> struct to_string_bit_size<uint16_t> { static constexpr int width = 4; };
template<> struct to_string_bit_size<uint32_t> { static constexpr int width = 8; };
template<> struct to_string_bit_size<uint64_t> { static constexpr int width = 16; };

template<typename UintT>
std::string to_string(std::vector<UintT> const &digest)
{
    std::ostringstream oss;
    oss << std::right << std::setfill('0') << std::hex;
    for(UintT bit : digest)
        oss << std::setw(to_string_bit_size<UintT>::width) << static_cast<uint64_t>(bit);
    return oss.str();
}
}
}
}

#endif // ONII_HASH_DETAIL_TO_STRING_HPP
