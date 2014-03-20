#ifndef ONII_AI_FUZZY_SET_OPERATOR_OR_HPP
#define ONII_AI_FUZZY_SET_OPERATOR_OR_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/set/operator/or.hpp
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
class or_operator :
    public abstract_set
{
public:

    or_operator(abstract_set const &lhs, abstract_set const &rhs) :
        m_lhs(lhs.clone()),
        m_rhs(rhs.clone())
    {}

    or_operator(or_operator const &rhs) :
        m_lhs(rhs.m_lhs->clone()),
        m_rhs(rhs.m_rhs->clone())
    {}

    or_operator &operator=(or_operator const &rhs)
    {
        delete m_lhs;
        delete m_rhs;
        m_lhs = rhs.m_lhs->clone();
        m_rhs = rhs.m_rhs->clone();
        return *this;
    }

    virtual ~or_operator()
    {
        delete m_lhs;
        delete m_rhs;
    }

    virtual abstract_set *clone() const
    {
        return new or_operator(*this);
    }

    virtual float membership(float crisp) const
    {
        return std::max(m_lhs->membership(crisp), m_rhs->membership(crisp));
    }

    virtual float representative() const
    {
        return std::max(m_lhs->representative(), m_rhs->representative());
    }

private:

    // data members
    abstract_set *m_lhs;
    abstract_set *m_rhs;

}; // class or_operator
} // namespace detail
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @brief OR operator for two fuzzy set
///
/// @param[in] lhs - first fuzzy set
/// @param[in] rhs - second fuzzy set
/// @return A special "OR" fuzzy set
/////////////////////////////////////////////////
detail::or_operator operator||(abstract_set const &lhs, abstract_set const &rhs)
{
    return detail::or_operator(lhs, rhs);
}
} // namespace set
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_SET_OPERATOR_OR_HPP
