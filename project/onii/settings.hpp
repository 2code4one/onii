#ifndef ONII_SETTINGS_CPP
#define ONII_SETTINGS_CPP

/////////////////////////////////////////////////
/// @file onii/settings.hpp
/////////////////////////////////////////////////

#include "detail/settings/ini.hpp"
#include "detail/settings/json.hpp"

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
    /// >ListKey3
    /// Value3
    /// Value4
    /// < ; End of the list
    /// @endcode
    /// Will become after reading (Key / Index / Value):
    /// @code
    /// Key1 / 0 / Value1
    /// Group1.Key2 / 0 / Value2
    /// Group1.ListKey3 / 0 / Value3
    /// Group1.ListKey3 / 1 / Value4
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
        auto it = m_datas.find(key);
        return it != m_datas.end() ? it->second.size() : 0;
    }

    /////////////////////////////////////////////////
    /// @brief Load settings from a file
    ///
    /// @param[in] filename - path to the file
    /// @remarks Use the file format defined by settings::settings
    /////////////////////////////////////////////////
    void read(std::string const &filename)
    {
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
    /// @param[in] index - property index (default: 0)
    /// @return the property value casted into T
    /////////////////////////////////////////////////
    template<typename T = std::string>
    T get(std::string const &key, unsigned int index = 0) const
    {
        return from_string<T>(m_datas.find(key)->second[index]);
    }

    /////////////////////////////////////////////////
    /// @brief Modifiy a property value
    ///
    /// @param[in] key - property name
    /// @param[in] value - property value
    /// @remarks Call the function @code settings::set(key, 0, value); @endcode
    /////////////////////////////////////////////////
    template<typename T>
    void set(std::string const &key, T const &value)
    {
        set(key, 0, value);
    }

    /////////////////////////////////////////////////
    /// @brief Modifiy a property value
    ///
    /// @param[in] key - property name
    /// @param[in] index - property index
    /// @param[in] value - property value
    /// @remarks If the property doesn't exists, this function call @code settings::add(key, value); @endcode
    /////////////////////////////////////////////////
    template<typename T>
    void set(std::string const &key, unsigned int index, T const &value)
    {
        if(count(key) > 0)
            m_datas[key][index] = to_string(value);
        else
            add(key, value);
    }

    /////////////////////////////////////////////////
    /// @brief Add a property value
    ///
    /// @param[in] key - property name
    /// @param[in] value - property value
    /////////////////////////////////////////////////
    template<typename T>
    void add(std::string const &key, T const &value)
    {
        m_datas[key].push_back(to_string(value));
    }

    /////////////////////////////////////////////////
    /// @brief Erase a specific property
    ///
    /// @param[in] key - property name
    /// @param[in] index - property index (default: 0)
    /////////////////////////////////////////////////
    void erase(std::string const &key, unsigned int index = 0)
    {
        m_datas[key].erase(m_datas[key].begin() + index);
        if(count(key) == 0)
            erase_all(key);
    }

    /////////////////////////////////////////////////
    /// @brief Erase all properties matched by name
    ///
    /// @param[in] key - property name
    /////////////////////////////////////////////////
    void erase_all(std::string const &key)
    {
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
