#ifndef ONII_AI_FUZZY_SET_LEFT_SHOULDER_HPP
#define ONII_AI_FUZZY_SET_LEFT_SHOULDER_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/set/left_shoulder.hpp
/////////////////////////////////////////////////

#include "abstract_set.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::ai
/////////////////////////////////////////////////
namespace ai
{
/////////////////////////////////////////////////
/// @namespace onii::ai::fuzzy
/////////////////////////////////////////////////
namespace fuzzy
{
/////////////////////////////////////////////////
/// @namespace onii::ai::fuzzy::set
/////////////////////////////////////////////////
namespace set
{
/////////////////////////////////////////////////
/// @class left_shoulder
/// @brief Left shoulder shape fuzzy set
/////////////////////////////////////////////////
class left_shoulder :
    public abstract_set
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] left_offset - left offset
    /// @param[in] peak - peak
    /// @param[in] right_offset - right offset
    /// @remarks The right offset must not be equal with peak!
    ///          If you want that, please look:
    ///          onii::ai::fuzzy::set::right_shoulder
    /////////////////////////////////////////////////
    left_shoulder(float left_offset, float peak, float right_offset) :
        m_left_offset(left_offset),
        m_peak(peak),
        m_right_offset(right_offset)
    {}

    /////////////////////////////////////////////////
    /// @brief Virtual destructor
    /////////////////////////////////////////////////
    virtual ~left_shoulder()
    {}

    /////////////////////////////////////////////////
    /// @brief Clone idiom
    ///
    /// @return A dynamic clone of the current instance
    /////////////////////////////////////////////////
    virtual abstract_set *clone() const
    {
        return new left_shoulder(*this);
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
        if(crisp < m_left_offset || crisp >= m_right_offset)
            return 0.f;
        else if(crisp > m_peak)
            return 1.f - ((crisp - m_peak) / (m_right_offset - m_peak));
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
        return (m_left_offset + m_peak) / 2.f;
    }

private:

    // data members
    float m_left_offset;
    float m_peak;
    float m_right_offset;

}; // class left_shoulder
} // namespace set
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_SET_LEFT_SHOULDER_HPP
