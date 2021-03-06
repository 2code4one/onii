#ifndef ONII_FUZZY_SET_SINGLETON_HPP
#define ONII_FUZZY_SET_SINGLETON_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/set/singleton.hpp
/////////////////////////////////////////////////

#include "abstract_set.hpp"
#include "../../float/equal.hpp"

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
/// @class singleton
/// @brief Discrete shape fuzzy set
/////////////////////////////////////////////////
class singleton :
    public abstract_set
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] peak - peak
    /////////////////////////////////////////////////
    singleton(float peak) :
        m_peak(peak)
    {}

    /////////////////////////////////////////////////
    /// @brief Virtual destructor
    /////////////////////////////////////////////////
    virtual ~singleton()
    {}

    /////////////////////////////////////////////////
    /// @brief Clone idiom
    ///
    /// @return A dynamic clone of the current instance
    /////////////////////////////////////////////////
    virtual abstract_set *clone() const
    {
        return new singleton(*this);
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
        return onii::equal(crisp, m_peak);
    }

    /////////////////////////////////////////////////
    /// @brief Get the representative value
    ///
    /// @return The representative value of the set
    /// @remarks This is for the max_av defuzzification
    /////////////////////////////////////////////////
    virtual float representative() const
    {
        return m_peak;
    }

private:

    // data members
    float m_peak;

}; // class singleton
} // namespace set
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_SET_SINGLETON_HPP
