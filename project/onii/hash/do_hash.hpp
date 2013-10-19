#ifndef ONII_HASH_DO_HASH_HPP
#define ONII_HASH_DO_HASH_HPP

namespace onii
{
inline
std::string do_hash(std::string const &message, std::string(*hash_function)(std::string const&))
{
    return hash_function(message);
}
}

#endif // ONII_HASH_DO_HASH_HPP
