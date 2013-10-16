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
template<typename UintT>
std::string to_string(std::vector<UintT> const &digest)
{
    std::ostringstream oss;
    oss << std::right << std::setfill('0') << std::hex;
    for(UintT bit : digest)
        oss << std::setw(sizeof(UintT) * 2) << static_cast<uint64_t>(bit);
    return oss.str();
}
}
}
}

#endif // ONII_HASH_DETAIL_TO_STRING_HPP
