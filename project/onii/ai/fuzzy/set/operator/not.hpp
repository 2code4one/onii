#ifndef ONII_AI_FUZZY_SET_OPERATOR_NOT_HPP
#define ONII_AI_FUZZY_SET_OPERATOR_NOT_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/set/operator/not.hpp
/////////////////////////////////////////////////

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
class not_operator :
    public abstract_set
{
public:

    not_operator(abstract_set const &set) :
        m_set(set.clone())
    {}

    not_operator(not_operator const &rhs) :
        m_set(rhs.m_set->clone())
    {}

    not_operator &operator=(not_operator const &rhs)
    {
        not_operator tmp(rhs);
        std::swap(m_set, tmp.m_set);
        return *this;
    }

    virtual ~not_operator()
    {
        delete m_set;
    }

    virtual abstract_set *clone() const
    {
        return new not_operator(*this);
    }

    virtual float membership(float crisp) const
    {
        return 1.f - m_set->membership(crisp);
    }

    virtual float membership(std::vector<manifold> const &m) const
    {
        return 1.f - m_set->membership(m);
    }

    virtual float representative() const
    {
        return 1.f - m_set->representative();
    }

private:

    // data members
    abstract_set *m_set;

}; // class not_operator
} // namespace detail
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @brief NOT operator for fuzzy set
///
/// @param[in] set - fuzzy set
/// @return A special "NOT" fuzzy set
/////////////////////////////////////////////////
detail::not_operator operator!(abstract_set const &set)
{
    return detail::not_operator(set);
}
} // namespace set
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_SET_OPERATOR_NOT_HPP
