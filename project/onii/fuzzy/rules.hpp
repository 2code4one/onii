#ifndef ONII_FUZZY_RULES_HPP
#define ONII_FUZZY_RULES_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/rules.hpp
/////////////////////////////////////////////////

#include <map>
#include <vector>
#include "variable.hpp"
#include "manifold.hpp"
#include "set/abstract_set.hpp"

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
/// @class rules
/// @brief Fuzzy inference
/////////////////////////////////////////////////
class rules
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] consequent - the consequent variable
    /////////////////////////////////////////////////
    rules(variable const &consequent) :
        m_consequent(consequent),
        m_rules()
    {}

    /////////////////////////////////////////////////
    /// @brief Copy constructor
    ///
    /// @param[in] rhs - rules to copy
    /////////////////////////////////////////////////
    rules(rules const &rhs) :
        m_consequent(rhs.m_consequent),
        m_rules()
    {
        auto it = rhs.m_rules.cbegin();
        for(; it != rhs.m_rules.cbegin(); ++it)
            m_rules[it->first->clone()] = it->second;
    }

    /////////////////////////////////////////////////
    /// @brief Assign operator
    ///
    /// @param[in] rhs - rules to copy
    /// @return *this
    /////////////////////////////////////////////////
    rules &operator=(rules const &rhs)
    {
        rules tmp(rhs);
        std::swap(m_consequent, tmp.m_consequent);
        std::swap(m_rules, tmp.m_rules);
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    ~rules()
    {
        auto it = m_rules.begin();
        for(; it != m_rules.end(); ++it)
            delete it->first;
    }

    /////////////////////////////////////////////////
    /// @brief Create a new rule
    ///
    /// @param[in] antecedents - the condition
    /// @param[in] consequent - the consequent set
    /// @see rules::rules(variable const&)
    /////////////////////////////////////////////////
    void operator()(set::abstract_set const &antecedents, std::string const &consequent)
    {
        m_rules[antecedents.clone()] = consequent;
    }

    /////////////////////////////////////////////////
    /// @brief Apply rules to get the consequent manifold
    ///
    /// @param[in] manifolds - the antecendents manifolds
    /// @return the consequent manifold
    /////////////////////////////////////////////////
    manifold operator()(std::vector<manifold> const &manifolds) const
    {
        // get the consequent manifold and "zeros it"
        manifold m = m_consequent(0.f);
        auto set = m.sets.begin();
        for(; set != m.sets.end(); ++set)
            set->second.membership = 0.f;

        // apply rules
        auto rule = m_rules.cbegin();
        for(; rule != m_rules.cend(); ++rule)
        {
            m.sets[rule->second].membership = std::max(
                m.sets[rule->second].membership,
                rule->first->membership(manifolds)
            );
        }

        return m;
    }

private:

    // data members
    variable m_consequent;
    std::map<set::abstract_set*, std::string> m_rules;

}; // class rules
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_RULES_HPP
