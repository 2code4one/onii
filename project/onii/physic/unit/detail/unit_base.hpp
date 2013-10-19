#ifndef ONII_PHYSIC_UNIT_DETAIL_UNIT_BASE_HPP
#define ONII_PHYSIC_UNIT_DETAIL_UNIT_BASE_HPP

namespace onii
{
namespace physic
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
} // namespace detail
} // namespace unit
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_UNIT_DETAIL_UNIT_BASE_HPP
