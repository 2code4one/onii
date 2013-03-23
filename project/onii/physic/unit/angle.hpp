#ifndef ONII_PHYSIC_UNIT_ANGLE_HPP
#define ONII_PHYSIC_UNIT_ANGLE_HPP

#include "detail/unit_base.hpp"

namespace onii
{
namespace physic
{
namespace unit
{
class angle :
    public detail::unit_base<angle, int>
{
public:

    typedef int degree_type;
    typedef float radian_type;

    static constexpr radian_type pi = 3.14f;

    angle(degree_type degree = 0) :
        unit_base(degree)
    {}

    degree_type deg() const
    {
        return m_value;
    }

    radian_type rad() const
    {
        return deg() * pi / 180.f;
    }

    static angle deg(degree_type degree)
    {
        return {degree % 360};
    }

    static angle rad(radian_type radian)
    {
        return deg(radian * 180.f / pi);
    }
};
} // namespace unit
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_UNIT_ANGLE_HPP
