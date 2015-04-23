#ifndef ONII_FUZZY_SET_RIGHT_SHOULDER_HPP
#define ONII_FUZZY_SET_RIGHT_SHOULDER_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/set/right_shoulder.hpp
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
/// @class right_shoulder
/// @brief Right shoulder shape fuzzy set
/////////////////////////////////////////////////
class right_shoulder :
    public abstract_set
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] left_offset - left offset
    /// @param[in] peak - peak
    /// @param[in] right_offset - right offset
    /// @remarks The left offset must not be equal with peak!
    ///          If you want that, please look:
    ///          onii::fuzzy::set::left_shoulder
    /////////////////////////////////////////////////
    right_shoulder(float left_offset, float peak, float right_offset) :
        m_left_offset(left_offset),
        m_peak(peak),
        m_right_offset(right_offset)
    {}

    /////////////////////////////////////////////////
    /// @brief Virtual destructor
    /////////////////////////////////////////////////
    virtual ~right_shoulder()
    {}

    /////////////////////////////////////////////////
    /// @brief Clone idiom
    ///
    /// @return A dynamic clone of the current instance
    /////////////////////////////////////////////////
    virtual abstract_set *clone() const
    {
        return new right_shoulder(*this);
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
        if(crisp <= m_left_offset || crisp > m_right_offset)
            return 0.f;
        else if(crisp < m_peak)
            return (crisp - m_left_offset) / (m_peak - m_left_offset);
        else
            return 1.f;
    }

    /////////////////////////////////////////////////
    /// @brief Get the representative value
    ///
    /// @return The representative value of the set
    /// @remarks This is for the max_av defuzzification
    /////////////////////////////////////////////////
    virtual float representative() const
    {
        return (m_peak + m_right_offset) / 2.f;
    }

private:

    // data members
    float m_left_offset;
    float m_peak;
    float m_right_offset;

}; // class right_shoulder
} // namespace set
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_SET_RIGHT_SHOULDER_HPP
