#ifndef ONII_CORE_ANY_HPP
#define ONII_CORE_ANY_HPP

#warning to finish

namespace onii
{
namespace core
{
class any
{
public:

    any() :
        m_type(nullptr),
        m_value(nullptr)
    {}

    template<typename T>
    any(T value) :
        m_type(get_type<T>()),
        m_value(&value)
    {}

    template<typename T>
    bool is() const
    {
        return m_type == get_type<T>();
    }

    template<typename T>
    T const &get() const
    {
        return *static_cast<T*>(m_value);
    }

    template<typename T>
    T &get()
    {
        return *static_cast<T*>(m_value);
    }

private:

    struct base_type
    {};

    template<typename T>
    struct value_type :
        base_type
    {};

    template<typename T>
    base_type *get_type() const
    {
        static value_type<T> value;
        return &value;
    }

    base_type *m_type;
    void *m_value;
};
} // namespace core
} // namespace onii

#endif // ONII_CORE_ANY_HPP
