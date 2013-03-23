#ifndef ONII_PHYSIC_UNIT_MASS_HPP
#define ONII_PHYSIC_UNIT_MASS_HPP

#include "detail/unit_base.hpp"

namespace onii
{
namespace physic
{
namespace unit
{
class mass :
    public detail::unit_base<mass, float>
{
public:

    typedef float mass_type;

    mass(mass_type kilogram = 0.f) :
        unit_base(kilogram)
    {}

    mass_type g() const
    {
        return kg() * 1000.f;
    }

    mass_type kg() const
    {
        return m_value;
    }

    mass_type t() const
    {
        return kg() / 1000.f;
    }

    static mass g(mass_type gram)
    {
        return kg(gram / 1000.f);
    }

    static mass kg(mass_type kilogram)
    {
        return {kilogram};
    }

    static mass t(mass_type tonne)
    {
        return kg(tonne * 1000.f);
    }
};
} // namespace unit
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_UNIT_MASS_HPP
