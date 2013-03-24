#ifndef ONII_PHYSIC_CONSTANT_GRAVITY_HPP
#define ONII_PHYSIC_CONSTANT_GRAVITY_HPP

namespace onii
{
namespace physic
{
namespace constant
{
class gravity
{
public:

    typedef float gravity_type;

    static constexpr gravity_type earth = 9.81f;
    static constexpr gravity_type moon = 1.62f;
    static constexpr gravity_type mars = 3.73f;
};
} // namespace constant
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_CONSTANT_GRAVITY_HPP
