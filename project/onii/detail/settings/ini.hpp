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
        std::string buf, key, grp;
        while(std::getline(ifs, buf))
        {
            // clear comments
            buf = splitter(buf).by_separators("#;").results()[0];

            // group
            if(buf[0] == '[')
                grp = trim(buf.substr(1, buf.find(']') - 1)) + ".";

            // new list
            else if(buf[0] == '>')
                key = trim(buf.substr(1));

            // end of the list
            else if(buf[0] == '<')
                key.clear();

            // property
            else if(key.empty() && buf.find("=") != std::string::npos)
            {
                split_results property = splitter(buf).by_separators("=").results();
                property[0] = trim(property[0]);
                datas[grp + property[0]].resize(1);
                datas[grp + property[0]][0] = trim(property[1]);
            }

            // list property
            else if(!key.empty())
                datas[grp + key].push_back(trim(buf));
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
            if(it.second.size() > 1)
            {
                ofs << ">" << it.first.substr(dot) << std::endl;
                for(auto const &value : it.second)
                    ofs << value << std::endl;
                ofs << "<" << std::endl;
            }
            else // property
                ofs << it.first.substr(dot) << "=" << it.second[0] << std::endl;
        }
    }
};
}
}
}

#endif // ONII_DETAIL_SETTINGS_INI_HPP
