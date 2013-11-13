#ifndef ONII_SETTINGS_CPP
#define ONII_SETTINGS_CPP

/////////////////////////////////////////////////
/// @file onii/settings.hpp
/////////////////////////////////////////////////

#include <algorithm>
#include "detail/settings/ini.hpp"
#include "detail/settings/json.hpp"

#include "log.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @class settings
/// @brief Manage settings file
/////////////////////////////////////////////////
class settings
{
public:

    void debug() const {
        for(auto const &it : m_datas)
            log::debug() << it.first << " = " << it.second;
    }

    /////////////////////////////////////////////////
    /// @enum format
    /// @brief Settings file format
    /// @see settings::settings for details
    /////////////////////////////////////////////////
    enum class format
    {
        ini,    ///< INI file format
        json    ///< JSON file format (soon)
    };

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] file_format - the file format to use
    ///
    /// @b INI file format:
    /// @code
    /// ; All at the right of ';' or '#' is a comment
    /// Key1=Value1
    /// [Group1]
    /// Key2=Value2
    /// ListKey3[]=Value3
    /// ListKey3[]=Value4
    /// @endcode
    /// Will become after reading (Key / Value):
    /// @code
    /// Key1 / Value1
    /// Group1.Key2 / Value2
    /// Group1.ListKey3[0] / Value3
    /// Group1.ListKey3[1] / Value4
    /// @endcode
    ///
    /// @b JSON file format:
    /// @code
    /// soon
    /// @endcode
    /////////////////////////////////////////////////
    settings(format file_format) :
        m_format(nullptr),
        m_datas()
    {
        // get the good format
        if(file_format == format::ini)
            m_format = new detail::settings::ini;
        else if(file_format == format::json)
            m_format = new detail::settings::json;
    }

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    ~settings()
    {
        // free memory
        delete m_format;
    }

    /////////////////////////////////////////////////
    /// @brief Copy constructor deleted
    /////////////////////////////////////////////////
    settings(settings const&) = delete;

    /////////////////////////////////////////////////
    /// @brief Assignment operator deleted
    /////////////////////////////////////////////////
    settings &operator=(settings const&) = delete;

    /////////////////////////////////////////////////
    /// @brief Is the settings valid ?
    ///
    /// @return true if the settings are valid
    /// @remarks Useful after calling the function settings::read
    /////////////////////////////////////////////////
    bool valid() const
    {
        return m_format->valid();
    }

    /////////////////////////////////////////////////
    /// @brief Count the number of property having the same key
    ///
    /// @param[in] key - key to search
    /// @return the number of property
    /// @remarks Useful to check if a key exists
    /////////////////////////////////////////////////
    unsigned int count(std::string const &key) const
    {
        // is the property a list ?
        auto tab = key.find("[]");
        if(tab != std::string::npos)
        {
            // get the key without the "[]"
            std::string k = key.substr(0, tab);

            // count property
            return std::count_if(
                m_datas.cbegin(),
                m_datas.cend(),
                [&k] (detail::settings::data::value_type const &value) {
                    return value.first.find(k) != std::string::npos;
                }
            );
        }

        // else it's a simple property
        else
            return m_datas.find(key) != m_datas.cend() ? 1 : 0;
    }

    /////////////////////////////////////////////////
    /// @brief Swap the values of two keys
    ///
    /// @param[in] key1 - first key
    /// @param[in] key2 - second key
    /////////////////////////////////////////////////
    void swap(std::string const &key1, std::string const &key2)
    {
        std::swap(m_datas[key1], m_datas[key2]);
    }

    /////////////////////////////////////////////////
    /// @brief Load settings from a file
    ///
    /// @param[in] filename - path to the file
    /// @remarks Use the file format defined by settings::settings
    /// @remarks This function call settings::clear before reading
    /////////////////////////////////////////////////
    void read(std::string const &filename)
    {
        clear();
        m_format->read(filename, m_datas);
    }

    /////////////////////////////////////////////////
    /// @brief Write settings into a file
    ///
    /// @param[in] filename - path to the file
    /// @remarks Use the file format defined by settings::settings
    /////////////////////////////////////////////////
    void write(std::string const &filename) const
    {
        m_format->write(filename, m_datas);
    }

    /////////////////////////////////////////////////
    /// @brief Return a property value
    ///
    /// @param[in] key - property name
    /// @return the property value casted into T
    /////////////////////////////////////////////////
    template<typename T = std::string>
    T get(std::string const &key) const
    {
        return from_string<T>(m_datas.find(key)->second);
    }

    /////////////////////////////////////////////////
    /// @brief Modifiy a property value
    ///
    /// @param[in] key - property name
    /// @param[in] value - property value
    /// @remarks If the property doesn't exists, this function create a new one
    /////////////////////////////////////////////////
    template<typename T>
    void set(std::string const &key, T const &value)
    {
        // is the key a list ?
        auto tab = key.find("[]");
        if(tab != std::string::npos)
        {
            unsigned int num = count(key);

            // the list exists, add a new value
            if(num > 0)
                m_datas[key.substr(0, tab + 1) + to_string(num) + "]"] = to_string(value);

            // create a new list at [0]
            else
                m_datas[key.substr(0, tab + 1) + "0]"] = to_string(value);
        }

        // else it's a simple property
        else
            m_datas[key] = to_string(value);
    }

    /////////////////////////////////////////////////
    /// @brief Erase a specific property
    ///
    /// @param[in] key - property name
    /////////////////////////////////////////////////
    void erase(std::string const &key)
    {
        // is the key a list ?
        auto tab = key.find("[]");
        if(tab != std::string::npos)
        {
            // get the key without the "[]"
            std::string k = key.substr(0, tab);

            // erase the complete list
            for(auto it = m_datas.begin(); it != m_datas.end(); )
            {
                if(it->first.find(k) != std::string::npos)
                    m_datas.erase(it++);
                else
                    ++it;
            }
        }

        // else it's a simple property
        else
            m_datas.erase(key);
    }

    /////////////////////////////////////////////////
    /// @brief Erase all properties
    /////////////////////////////////////////////////
    void clear()
    {
        m_datas.clear();
    }

private:

    detail::settings::format *m_format;
    detail::settings::data m_datas;
};
}

#endif // ONII_SETTINGS_CPP
