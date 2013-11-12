#ifndef ONII_DETAIL_SETTINGS_BASE_HPP
#define ONII_DETAIL_SETTINGS_BASE_HPP

#include <map>
#include <vector>
#include <string>
#include <fstream>

namespace onii
{
namespace detail
{
namespace settings
{
// data type, compare modified to put the no-group property before
struct data_key_compare
{
    bool operator()(std::string const &lhs, std::string const &rhs) const
    {
        bool rhsdot = rhs.find(".") != std::string::npos;
        if((lhs.find(".") != std::string::npos) == rhsdot)
            return std::less<std::string>()(lhs, rhs);
        else
            return rhsdot;
    }
};
typedef std::map<std::string, std::vector<std::string>, data_key_compare> data;

class format
{
public:

    format() :
        m_valid(true)
    {}

    virtual ~format()
    {}

    bool valid() const
    {
        return m_valid;
    }

    void read(std::string const &filename, data &datas)
    {
        datas.clear();
        std::ifstream ifs(filename.c_str());
        if(ifs)
            do_read(ifs, datas);
        else
            invalidate();
    }

    void write(std::string const &filename, data const &datas) const
    {
        std::ofstream ofs(filename.c_str());
        if(ofs)
            do_write(ofs, datas);
    }

protected:

    void invalidate()
    {
        m_valid = false;
    }

    virtual void do_read(std::ifstream &ifs, data &datas) = 0;
    virtual void do_write(std::ofstream &ofs, data const &datas) const = 0;

private:

    bool m_valid;
};
}
}
}

#endif // ONII_DETAIL_SETTINGS_BASE_HPP
