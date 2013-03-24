#ifndef ONII_CORE_SPLIT_HPP
#define ONII_CORE_SPLIT_HPP

#include <vector>
#include <string>
#include <algorithm>

namespace onii
{
namespace core
{
typedef std::vector<std::string> split_results;

class splitter
{
public:

    splitter(std::string const &str = "") :
        m_results(1, str)
    {}

    splitter &by_separators(std::string const &sep)
    {
        split_results copy = m_results;
        m_results.clear();
        for(std::string const &str : copy)
        {
            size_t last = 0;
            for(size_t i = last; i < str.size(); ++i)
            {
                if(sep.find(str[i]) != std::string::npos)
                {
                    m_results.push_back(str.substr(last, i - last));
                    last = i + 1;
                }
            }
            if(last == 0)
                m_results.push_back(str);
            else if(last - 1 < str.size())
                m_results.push_back(str.substr(last, str.size() - last));
        }
        return *this;
    }

    splitter &by_string(std::string const &sep)
    {
        split_results copy = m_results;
        m_results.clear();
        for(std::string const &str : copy)
        {
#warning todo
        }
        return *this;
    }

    splitter &remove_empty()
    {
        m_results.erase(std::remove_if(m_results.begin(),
                                       m_results.end(),
                                       [](std::string const &str) -> bool {
                                            return str.empty(); }),
                        m_results.end());
        return *this;
    }

    split_results const &results() const
    {
        return m_results;
    }

private:

    split_results m_results;
};
} // namespace core
} // namespace onii

#endif // ONII_CORE_SPLIT_HPP
