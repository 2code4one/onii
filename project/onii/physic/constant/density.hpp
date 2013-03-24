#ifndef ONII_PHYSIC_CONSTANT_DENSITY_HPP
#define ONII_PHYSIC_CONSTANT_DENSITY_HPP

namespace onii
{
namespace physic
{
namespace constant
{
class density
{
public:

    typedef unsigned int density_type;

    static constexpr density_type wood = 700;
    static constexpr density_type ice = 916;
    static constexpr density_type water = 1000;
    static constexpr density_type salt_water = 1030;
    static constexpr density_type aluminium = 2700;
    static constexpr density_type iron = 7870;
    static constexpr density_type silver = 10500;
    static constexpr density_type gold = 19320;
};
} // namespace constant
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_CONSTANT_DENSITY_HPP
