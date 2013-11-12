#ifndef ONII_SETTINGS_CPP
#define ONII_SETTINGS_CPP

/////////////////////////////////////////////////
/// @file onii/settings.hpp
/////////////////////////////////////////////////

#include "to_string.hpp"
#include "from_string.hpp"
#include "detail/settings/ini.hpp"
#include "detail/settings/json.hpp"

namespace onii
{
class settings
{
public:

    enum class format
    {
        ini,
        json
    };

    settings(format file_format) :
        m_format(nullptr),
        m_datas()
    {
        if(file_format == format::ini)
            m_format = new detail::settings::ini;
        else if(file_format == format::json)
            m_format = new detail::settings::json;
    }

    ~settings()
    {
        delete m_format;
    }

    settings(settings const &other) = delete;
    settings &operator=(settings const &other) = delete;

    bool valid() const
    {
        return m_format->valid();
    }

    unsigned int count(std::string const &key) const
    {
        auto it = m_datas.find(key);
        return it != m_datas.end() ? it->second.size() : 0;
    }

    void read(std::string const &filename)
    {
        m_format->read(filename, m_datas);
    }

    void write(std::string const &filename) const
    {
        m_format->write(filename, m_datas);
    }

    template<typename T = std::string>
    T get(std::string const &key, unsigned int index = 0) const
    {
        return from_string<T>(m_datas.find(key)->second[index]);
    }

    template<typename T>
    void set(std::string const &key, T const &value)
    {
        set(key, 0, value);
    }

    template<typename T>
    void set(std::string const &key, unsigned int index, T const &value)
    {
        if(count(key) > 0)
            m_datas[key][index] = to_string(value);
        else
            add(key, value);
    }

    template<typename T>
    void add(std::string const &key, T const &value)
    {
        m_datas[key].push_back(to_string(value));
    }

    void erase(std::string const &key, unsigned int index = 0)
    {
        m_datas[key].erase(m_datas[key].begin() + index);
        if(count(key) == 0)
            erase_all(key);
    }

    void erase_all(std::string const &key)
    {
        m_datas.erase(key);
    }

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
