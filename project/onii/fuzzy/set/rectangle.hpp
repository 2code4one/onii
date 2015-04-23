#ifndef ONII_FUZZY_SET_RECTANGLE_HPP
#define ONII_FUZZY_SET_RECTANGLE_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/set/rectangle.hpp
/////////////////////////////////////////////////

#include "abstract_set.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::fuzzy
/////////////////////////////////////////////////
namespace fuzzy
{
/////////////////////////////////////////////////
/// @namespace onii::fuzzy::set
/////////////////////////////////////////////////
namespace set
{
/////////////////////////////////////////////////
/// @class rectangle
/// @brief Rectangular shape fuzzy set
/////////////////////////////////////////////////
class rectangle :
    public abstract_set
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] left_peak - left peak
    /// @param[in] right_peak - right peak
    /////////////////////////////////////////////////
    rectangle(float left_peak, float right_peak) :
        m_left_peak(left_peak),
        m_right_peak(right_peak)
    {}

    /////////////////////////////////////////////////
    /// @brief Virtual destructor
    /////////////////////////////////////////////////
    virtual ~rectangle()
    {}

    /////////////////////////////////////////////////
    /// @brief Clone idiom
    ///
    /// @return A dynamic clone of the current instance
    /////////////////////////////////////////////////
    virtual abstract_set *clone() const
    {
        return new rectangle(*this);
    }

    /////////////////////////////////////////////////
    /// @brief Get the degree of membership
    ///
    /// @param[in] crisp - crisp value
    /// @return The degree of membership of crisp
    /// @remarks The degree of membership is a value between 0 and 1
    /////////////////////////////////////////////////
    virtual float membership(float crisp) const
    {
        return crisp >= m_left_peak && crisp <= m_right_peak;
    }

    /////////////////////////////////////////////////
    /// @brief Get the representative value
    ///
    /// @return The representative value of the set
    /// @remarks This is for the max_av defuzzification
    /////////////////////////////////////////////////
    virtual float representative() const
    {
        return (m_left_peak + m_right_peak) / 2.f;
    }

private:

    // data members
    float m_left_peak;
    float m_right_peak;

}; // class rectangle
} // namespace set
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_SET_RECTANGLE_HPP
