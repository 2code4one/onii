#ifndef ONII_HASH_DO_HASH_HPP
#define ONII_HASH_DO_HASH_HPP

/////////////////////////////////////////////////
/// @file onii/hash/do_hash.hpp
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Calculate the hash of a string
///
/// @param[in] message - string to calculate
/// @param[in] hash_function - hash function
/// @return hash_function(message);
/// @remarks See also onii::hash for some hash functions
/////////////////////////////////////////////////
inline
std::string do_hash(std::string const &message, std::string(*hash_function)(std::string const&))
{
    return hash_function(message);
}
}

#endif // ONII_HASH_DO_HASH_HPP
