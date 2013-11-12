#ifndef ONII_DETAIL_SETTINGS_JSON_HPP
#define ONII_DETAIL_SETTINGS_JSON_HPP

#include "base.hpp"

namespace onii
{
namespace detail
{
namespace settings
{
class json :
    public format
{
protected:

    virtual void do_read(std::ifstream &, data &)
    {

    }

    virtual void do_write(std::ofstream &, data const &) const
    {

    }
};
}
}
}

#endif // ONII_DETAIL_SETTINGS_JSON_HPP
