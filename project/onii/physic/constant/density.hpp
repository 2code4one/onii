#ifndef ONII_PHYSIC_CONSTANT_DENSITY_HPP
#define ONII_PHYSIC_CONSTANT_DENSITY_HPP

/////////////////////////////////////////////////
/// @file onii/physic/constant/density.hpp
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::physic
/////////////////////////////////////////////////
namespace physic
{
/////////////////////////////////////////////////
/// @namespace onii::physic::constant
/////////////////////////////////////////////////
namespace constant
{
/////////////////////////////////////////////////
/// @class density
/// @brief Some density constants
/////////////////////////////////////////////////
class density
{
public:

    /////////////////////////////////////////////////
    /// @brief Density constants type
    /////////////////////////////////////////////////
    typedef unsigned int density_type;

    /////////////////////////////////////////////////
    static constexpr density_type wood = 700;           ///< Wood density
    static constexpr density_type ice = 916;            ///< Ice density
    static constexpr density_type water = 1000;         ///< Water density
    static constexpr density_type salt_water = 1030;    ///< Salt water density
    static constexpr density_type aluminium = 2700;     ///< Aluminium density
    static constexpr density_type iron = 7870;          ///< Iron density
    static constexpr density_type silver = 10500;       ///< Silver density
    static constexpr density_type gold = 19320;         ///< Gold density
    /////////////////////////////////////////////////
};
} // namespace constant
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_CONSTANT_DENSITY_HPP
