#ifndef ONII_DETAIL_SETTINGS_INI_HPP
#define ONII_DETAIL_SETTINGS_INI_HPP

#include "base.hpp"
#include "../../split.hpp"

namespace onii
{
namespace detail
{
namespace settings
{
class ini :
    public format
{
protected:

    virtual void do_read(std::ifstream &ifs, data &datas)
    {

    }

    virtual void do_write(std::ofstream &ofs, data const &datas) const
    {

    }
};
}
}
}

#endif // ONII_DETAIL_SETTINGS_INI_HPP
