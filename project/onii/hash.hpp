#ifndef ONII_HASH_HPP
#define ONII_HASH_HPP

#include "hash/md5.hpp"
#include "hash/sha1.hpp"

namespace onii
{
inline
std::string do_hash(std::string const &message, std::string(*hash_function)(std::string const&) = hash::sha1)
{
    return hash_function(message);
}
}

#endif // ONII_HASH_HPP
