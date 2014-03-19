#ifndef ONII_AI_FUZZY_SET_OPERATOR_AND_HPP
#define ONII_AI_FUZZY_SET_OPERATOR_AND_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/set/operator/and.hpp
/////////////////////////////////////////////////

#include <algorithm>
#include "../abstract_set.hpp"

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
/// @cond IGNORE
namespace detail
{
class and_operator :
    public abstract_set
{
public:

    and_operator(abstract_set const &lhs, abstract_set const &rhs) :
        m_lhs(lhs.clone()),
        m_rhs(rhs.clone())
    {}

    and_operator(and_operator const &rhs) :
        m_lhs(rhs.m_lhs->clone()),
        m_rhs(rhs.m_rhs->clone())
    {}

    and_operator &operator=(and_operator const &rhs)
    {
        delete m_lhs;
        delete m_rhs;
        m_lhs = rhs.m_lhs->clone();
        m_rhs = rhs.m_rhs->clone();
        return *this;
    }

    virtual ~and_operator()
    {
        delete m_lhs;
        delete m_rhs;
    }

    virtual abstract_set *clone() const
    {
        return new and_operator(*this);
    }

    virtual float membership(float crisp) const
    {
        return std::min(m_lhs->membership(crisp), m_rhs->membership(crisp));
    }

private:

    // data members
    abstract_set *m_lhs;
    abstract_set *m_rhs;

}; // class and_operator
} // namespace detail
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @brief AND operator for two fuzzy set
///
/// @param[in] lhs - first fuzzy set
/// @param[in] rhs - second fuzzy set
/// @return A special "AND" fuzzy set
/////////////////////////////////////////////////
detail::and_operator operator&&(abstract_set const &lhs, abstract_set const &rhs)
{
    return detail::and_operator(lhs, rhs);
}
} // namespace set
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_SET_OPERATOR_AND_HPP
