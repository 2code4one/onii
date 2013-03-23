#ifndef ONII_PHYSIC_UNIT_LENGTH_HPP
#define ONII_PHYSIC_UNIT_LENGTH_HPP

#include "detail/unit_base.hpp"

namespace onii
{
namespace physic
{
namespace unit
{
class length :
    public detail::unit_base<length, float>
{
public:

    typedef float length_type;

    length(length_type metre = 0.f) :
        unit_base(metre)
    {}

    length_type mm() const
    {
        return m() * 1000.f;
    }

    length_type cm() const
    {
        return m() * 100.f;
    }

    length_type m() const
    {
        return m_value;
    }

    length_type km() const
    {
        return m() / 1000.f;
    }

    static length mm(length_type millimetre)
    {
        return m(millimetre / 1000.f);
    }

    static length cm(length_type centimetre)
    {
        return m(centimetre / 100.f);
    }

    static length m(length_type metre)
    {
        return {metre};
    }

    static length km(length_type kilometre)
    {
        return m(kilometre * 1000.f);
    }
};
} // namespace unit
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_UNIT_LENGTH_HPP
