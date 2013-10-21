#ifndef ONII_PHYSIC_UNIT_LENGTH_HPP
#define ONII_PHYSIC_UNIT_LENGTH_HPP

/////////////////////////////////////////////////
/// @file onii/physic/unit/length.hpp
/////////////////////////////////////////////////

#include "detail/unit_base.hpp"

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
/// @namespace onii::physic::unit
/////////////////////////////////////////////////
namespace unit
{
/////////////////////////////////////////////////
/// @class length
/////////////////////////////////////////////////
class length :
    public detail::unit_base<length, float>
{
public:

    /////////////////////////////////////////////////
    /// @brief Length type
    /////////////////////////////////////////////////
    typedef float length_type;

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param metre - length in metre
    /////////////////////////////////////////////////
    length(length_type metre = 0.f) :
        unit_base(metre)
    {}

    /////////////////////////////////////////////////
    /// @brief Get the length in millimetre
    ///
    /// @return The length in millimetre
    /////////////////////////////////////////////////
    length_type mm() const
    {
        return m() * 1000.f;
    }

    /////////////////////////////////////////////////
    /// @brief Get the length in centimetre
    ///
    /// @return The length in centimetre
    /////////////////////////////////////////////////
    length_type cm() const
    {
        return m() * 100.f;
    }

    /////////////////////////////////////////////////
    /// @brief Get the length in metre
    ///
    /// @return The length in metre
    /////////////////////////////////////////////////
    length_type m() const
    {
        return m_value;
    }

    /////////////////////////////////////////////////
    /// @brief Get the length in kilometre
    ///
    /// @return The length in kilometre
    /////////////////////////////////////////////////
    length_type km() const
    {
        return m() / 1000.f;
    }

    /////////////////////////////////////////////////
    /// @brief Create a length instance from millimetre
    ///
    /// @param millimetre - the length in millimetre
    /// @return The new length instance
    /////////////////////////////////////////////////
    static length mm(length_type millimetre)
    {
        return m(millimetre / 1000.f);
    }

    /////////////////////////////////////////////////
    /// @brief Create a length instance from centimetre
    ///
    /// @param centimetre - the length in centimetre
    /// @return The new length instance
    /////////////////////////////////////////////////
    static length cm(length_type centimetre)
    {
        return m(centimetre / 100.f);
    }

    /////////////////////////////////////////////////
    /// @brief Create a length instance from metre
    ///
    /// @param metre - the length in metre
    /// @return The new length instance
    /////////////////////////////////////////////////
    static length m(length_type metre)
    {
        return {metre};
    }

    /////////////////////////////////////////////////
    /// @brief Create a length instance from kilometre
    ///
    /// @param kilometre - the length in kilometre
    /// @return The new length instance
    /////////////////////////////////////////////////
    static length km(length_type kilometre)
    {
        return m(kilometre * 1000.f);
    }
};
} // namespace unit
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_UNIT_LENGTH_HPP
