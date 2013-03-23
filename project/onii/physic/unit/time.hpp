#ifndef ONII_PHYSIC_UNIT_TIME_HPP
#define ONII_PHYSIC_UNIT_TIME_HPP

#include "detail/unit_base.hpp"

namespace onii
{
namespace physic
{
namespace unit
{
class time :
    public detail::unit_base<time, float>
{
public:

    typedef float time_type;

    time(time_type second = 0.f) :
        unit_base(second)
    {}

    time_type ms() const
    {
        return s() * 1000.f;
    }

    time_type s() const
    {
        return m_value;
    }

    time_type min() const
    {
        return s() / 60.f;
    }

    static time ms(time_type millisecond)
    {
        return s(millisecond / 1000.f);
    }

    static time s(time_type second)
    {
        return {second};
    }

    static time min(time_type minute)
    {
        return s(minute * 60.f);
    }
};
} // namespace unit
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_UNIT_TIME_HPP
