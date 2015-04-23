#ifndef ONII_UNIT_DETAIL_UNIT_BASE_HPP
#define ONII_UNIT_DETAIL_UNIT_BASE_HPP

namespace onii
{
namespace unit
{
namespace detail
{
template<typename DerivedClass, typename ValueType>
class unit_base
{
public:

    typedef float scalar_type;

    DerivedClass &operator+=(unit_base const &b)
    {
        m_value += b.m_value;
        return *static_cast<DerivedClass*>(this);
    }

    DerivedClass &operator-=(unit_base const &b)
    {
        m_value -= b.m_value;
        return *static_cast<DerivedClass*>(this);
    }

    DerivedClass &operator*=(scalar_type s)
    {
        m_value *= s;
        return *static_cast<DerivedClass*>(this);
    }

    DerivedClass &operator/=(scalar_type s)
    {
        m_value /= s;
        return *static_cast<DerivedClass*>(this);
    }

protected:

    unit_base(ValueType value) :
        m_value(value)
    {}

    virtual ~unit_base()
    {}

    ValueType m_value;

private:

    template<typename T, typename U>
    friend bool operator==(unit_base<T, U> const &, unit_base<T, U> const &);

    template<typename T, typename U>
    friend bool operator<(unit_base<T, U> const &, unit_base<T, U> const &);
};

template<typename DerivedClass, typename ValueType>
DerivedClass operator+(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return unit_base<DerivedClass, ValueType>(a) += b;
}

template<typename DerivedClass, typename ValueType>
DerivedClass operator-(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return unit_base<DerivedClass, ValueType>(a) -= b;
}

template<typename DerivedClass, typename ValueType>
DerivedClass operator*(unit_base<DerivedClass, ValueType> const &a, typename unit_base<DerivedClass, ValueType>::scalar_type s)
{
    return unit_base<DerivedClass, ValueType>(a) *= s;
}

template<typename DerivedClass, typename ValueType>
DerivedClass operator*(typename unit_base<DerivedClass, ValueType>::scalar_type s, unit_base<DerivedClass, ValueType> const &a)
{
    return unit_base<DerivedClass, ValueType>(a) *= s;
}

template<typename DerivedClass, typename ValueType>
DerivedClass operator/(unit_base<DerivedClass, ValueType> const &a, typename unit_base<DerivedClass, ValueType>::scalar_type s)
{
    return unit_base<DerivedClass, ValueType>(a) /= s;
}

template<typename DerivedClass, typename ValueType>
bool operator==(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return a.m_value == b.m_value;
}

template<typename DerivedClass, typename ValueType>
bool operator!=(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return !(a == b);
}

template<typename DerivedClass, typename ValueType>
bool operator<(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return a.m_value < b.m_value;
}

template<typename DerivedClass, typename ValueType>
bool operator<=(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return !(b < a);
}

template<typename DerivedClass, typename ValueType>
bool operator>(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return b < a;
}

template<typename DerivedClass, typename ValueType>
bool operator>=(unit_base<DerivedClass, ValueType> const &a, unit_base<DerivedClass, ValueType> const &b)
{
    return !(a < b);
}
} // namespace detail
} // namespace unit
} // namespace onii

#endif // ONII_UNIT_DETAIL_UNIT_BASE_HPP
