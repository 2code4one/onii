#ifndef ONII_DETAIL_SETTINGS_INI_HPP
#define ONII_DETAIL_SETTINGS_INI_HPP

#include "base.hpp"
#include "../../split.hpp"
#include "../../string.hpp"

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
        unsigned long index = 0;
        std::string buf, key, grp, tmp;
        while(std::getline(ifs, buf))
        {
            // clear comments
            buf = splitter(buf).by_separators("#;").results()[0];

            // group
            if(buf[0] == '[')
                grp = trim(buf.substr(1, buf.find(']') - 1)) + ".";

            // continue if empty line
            if(buf.find("=") == std::string::npos)
                continue;

            // property
            split_results property = splitter(buf).by_separators("=").results();

            // is a list ?
            key = trim(property[0]);
            if(key[key.size() - 1] == ']')
            {
                if(tmp != key)
                {
                    tmp = key;
                    index = 0;
                }
                key = trim(key.substr(0, key.rfind("[")));
                datas[grp + key + "[" + to_string(index++) + "]"] = trim(property[1]);
            }

            // else it's a simple property
            else
                datas[grp + key] = trim(property[1]);
        }
    }

    virtual void do_write(std::ofstream &ofs, data const &datas) const
    {
        std::string grp, tmp;
        for(auto const &it : datas)
        {
            // has a group ?
            auto dot = it.first.find(".");
            if(dot != std::string::npos)
            {
                // is the same group ?
                tmp = it.first.substr(0, dot++);
                if(grp != tmp)
                {
                    // write group
                    grp = tmp;
                    ofs << std::endl << "[" << grp << "]" << std::endl;
                }
            }
            else // no group
                dot = 0;

            // list
            if(it.first[it.first.size() - 1] == ']')
                ofs << it.first.substr(dot, it.first.rfind("[") - dot) << "[]=" << it.second << std::endl;
            else // property
                ofs << it.first.substr(dot) << "=" << it.second << std::endl;
        }
    }
};
}
}
}

#endif // ONII_DETAIL_SETTINGS_INI_HPP
