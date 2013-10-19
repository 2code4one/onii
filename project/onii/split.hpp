#ifndef ONII_SPLIT_HPP
#define ONII_SPLIT_HPP

/////////////////////////////////////////////////
/// @file onii/split.hpp
/////////////////////////////////////////////////

#include <vector>
#include <string>
#include <algorithm>

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Results of a splitted string
/////////////////////////////////////////////////
typedef std::vector<std::string> split_results;

/////////////////////////////////////////////////
/// @class splitter
/// @brief String splitter
/////////////////////////////////////////////////
class splitter
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] str - string to split
    /////////////////////////////////////////////////
    splitter(std::string const &str = "") :
        m_results(1, str)
    {}

    /////////////////////////////////////////////////
    /// @brief Split by separators
    ///
    /// @param[in] sep - separators
    /// @return *this
    /////////////////////////////////////////////////
    splitter &by_separators(std::string const &sep)
    {
        split_results save = m_results;
        m_results.clear();
        for(std::string const &str : save)
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

    /////////////////////////////////////////////////
    /// @brief Split by a complete string
    ///
    /// @param[in] sep - string separator
    /// @return *this
    /////////////////////////////////////////////////
    splitter &by_string(std::string const &sep)
    {
        split_results save = m_results;
        m_results.clear();
        for(std::string const &str : save)
        {
            m_results.push_back(str);
            auto pos = str.find(sep);
            while(pos != std::string::npos)
            {
                std::string temp = m_results.back();
                m_results.pop_back();
                m_results.push_back(temp.substr(0, pos));
                m_results.push_back(temp.substr(pos + sep.size()));
                pos = m_results.back().find(sep);
            }
        }
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Remove the empty results
    ///
    /// @return *this
    /////////////////////////////////////////////////
    splitter &remove_empty()
    {
        m_results.erase(std::remove_if(m_results.begin(),
                                       m_results.end(),
                                       [](std::string const &str) -> bool {
                                            return str.empty(); }),
                        m_results.end());
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Get the splitted string
    ///
    /// @return The splitted string as a onii::split_results
    /////////////////////////////////////////////////
    split_results const &results() const
    {
        return m_results;
    }

private:

    split_results m_results;
};
} // namespace onii

#endif // ONII_SPLIT_HPP
