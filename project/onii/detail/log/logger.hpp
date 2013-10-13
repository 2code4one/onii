#ifndef ONII_DETAIL_LOG_LOGGER_HPP
#define ONII_DETAIL_LOG_LOGGER_HPP

#include <iostream>
#include "../../thread_safe.hpp"

namespace onii
{
namespace detail
{
namespace log
{
template<int ID>
class base_logger
{
public:

    base_logger(char const *level, char const *tag, int indent_level)
    {
        ONII_THREAD_SAFE
        if(active())
        {
            for(int i = 0; i < indent_level; ++i)
                stream() << "    ";
            stream() << "[" << level << "]";
            if(tag != nullptr)
                stream() << "[" << tag << "]";
            stream() << ' ';
        }
    }

    ~base_logger()
    {
        ONII_THREAD_SAFE
        try
        {
            if(active())
                stream() << std::endl;
        }
        catch(...)
        {}
    }

    template<typename T>
    base_logger &operator<<(T const &value)
    {
        ONII_THREAD_SAFE
        if(active())
            stream() << value;
        return *this;
    }

    static void active(bool active)
    {
        ONII_THREAD_SAFE
        m_active = active;
    }

    static bool active()
    {
        return m_active;
    }

    static void redirect(std::ostream &os)
    {
        ONII_THREAD_SAFE
        stream().rdbuf(os.rdbuf());
    }

    static std::ostream &stream()
    {
        return m_os;
    }

private:

    static bool m_active;
    static std::ostream m_os;
};

template<int ID> bool base_logger<ID>::m_active = true;
template<int ID> std::ostream base_logger<ID>::m_os(std::cerr.rdbuf());
}
}
}

#define ONII_DETAIL_LOG_DEFINE_LEVEL(id, name)  \
    struct name : onii::detail::log::base_logger<id> {  \
        name(char const *t = nullptr, int i = 0) : onii::detail::log::base_logger<id>(#name, t, i) {}  \
        name(int i) : onii::detail::log::base_logger<id>(#name, nullptr, i) {}  \
    }

#endif // ONII_DETAIL_LOG_LOGGER_HPP
