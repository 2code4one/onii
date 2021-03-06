#ifndef ONII_FUZZY_HEDGE_ABSTRACT_HEDGE_HPP
#define ONII_FUZZY_HEDGE_ABSTRACT_HEDGE_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/hedge/abstract_hedge.hpp
/////////////////////////////////////////////////

#include "../set/abstract_set.hpp"

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
/// @namespace onii::fuzzy::hedge
/////////////////////////////////////////////////
namespace hedge
{
/////////////////////////////////////////////////
/// @class abstract_hedge
/// @brief Base class for fuzzy set hedge
/////////////////////////////////////////////////
class abstract_hedge :
    public set::abstract_set
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] set - fuzzy set to hedge
    /////////////////////////////////////////////////
    abstract_hedge(abstract_set const &set) :
        m_set(set.clone())
    {}

    /////////////////////////////////////////////////
    /// @brief Copy constructor
    ///
    /// @param[in] rhs - an other hedge
    /////////////////////////////////////////////////
    abstract_hedge(abstract_hedge const &rhs) :
        m_set(rhs.m_set->clone())
    {}

    /////////////////////////////////////////////////
    /// @brief Assign operator
    ///
    /// @param[in] rhs - other hedge to copy
    /// @return *this
    /////////////////////////////////////////////////
    abstract_hedge &operator=(abstract_hedge const &rhs)
    {
        delete m_set;
        m_set = rhs.m_set->clone();
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    virtual ~abstract_hedge()
    {
        delete m_set;
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
        return m_set->membership(crisp);
    }

    /////////////////////////////////////////////////
    /// @brief Get the representative value
    ///
    /// @return The representative value of the set
    /// @remarks This is for the max_av defuzzification
    /////////////////////////////////////////////////
    virtual float representative() const
    {
        return m_set->representative();
    }

private:

    // data members
    abstract_set *m_set;

}; // class abstract_hedge
} // namespace hedge
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_HEDGE_ABSTRACT_HEDGE_HPP
