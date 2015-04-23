#ifndef ONII_UNIT_ANGLE_HPP
#define ONII_UNIT_ANGLE_HPP

/////////////////////////////////////////////////
/// @file onii/unit/angle.hpp
/////////////////////////////////////////////////

#include "detail/unit_base.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::unit
/////////////////////////////////////////////////
namespace unit
{
/////////////////////////////////////////////////
/// @class angle
/////////////////////////////////////////////////
class angle :
    public detail::unit_base<angle, int>
{
public:

    /////////////////////////////////////////////////
    /// @brief Type of angle in degree
    /////////////////////////////////////////////////
    typedef int degree_type;

    /////////////////////////////////////////////////
    /// @brief Type of angle in radian
    /////////////////////////////////////////////////
    typedef float radian_type;

    /////////////////////////////////////////////////
    static constexpr radian_type pi = 3.14f;    ///< Constant PI
    /////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param degree - angle in degree
    /////////////////////////////////////////////////
    angle(degree_type degree = 0) :
        unit_base(degree)
    {}

    /////////////////////////////////////////////////
    /// @brief Get the angle in degree
    ///
    /// @return The angle in degree
    /////////////////////////////////////////////////
    degree_type deg() const
    {
        return m_value;
    }

    /////////////////////////////////////////////////
    /// @brief Get the angle in radian
    ///
    /// @return The angle in radian
    /////////////////////////////////////////////////
    radian_type rad() const
    {
        return deg() * pi / 180.f;
    }

    /////////////////////////////////////////////////
    /// @brief Create an angle instance from degree
    ///
    /// @param degree - the angle in degree
    /// @return The new angle instance
    /////////////////////////////////////////////////
    static angle deg(degree_type degree)
    {
        return {degree % 360};
    }

    /// @brief Create an angle instance from radian
    ///
    /// @param radian - the angle in radian
    /// @return The new angle instance
    /////////////////////////////////////////////////
    static angle rad(radian_type radian)
    {
        return deg(radian * 180.f / pi);
    }
};
} // namespace unit
} // namespace onii

#endif // ONII_UNIT_ANGLE_HPP