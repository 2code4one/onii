#ifndef ONII_AI_FUZZY_VARIABLE_HPP
#define ONII_AI_FUZZY_VARIABLE_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/variable.hpp
/////////////////////////////////////////////////

#include <map>
#include <string>
#include "set/abstract_set.hpp"
#include "manifold.hpp"

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
/// @class variable
/// @brief Class for fuzzy linguistic variable
/////////////////////////////////////////////////
class variable
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] name - The variable name
    /// @param[in] left_range - The variable min range
    /// @param[in] right_range - The variable max range
    /////////////////////////////////////////////////
    variable(std::string const &name, float left_range, float right_range) :
        m_left_range(left_range),
        m_right_range(right_range),
        m_name(name),
        m_sets()
    {}

    /////////////////////////////////////////////////
    /// @brief Copy constructor
    ///
    /// @param[in] rhs - The variable to copy
    /////////////////////////////////////////////////
    variable(variable const &rhs) :
        m_left_range(rhs.m_left_range),
        m_right_range(rhs.m_right_range),
        m_name(rhs.m_name),
        m_sets()
    {
        auto it = rhs.m_sets.cbegin();
        for(; it != rhs.m_sets.cend(); ++it)
            m_sets[it->first] = it->second->clone();
    }

    /////////////////////////////////////////////////
    /// @brief Assign operator
    ///
    /// @param[in] rhs - The variable to copy
    /// @return *this
    /////////////////////////////////////////////////
    variable &operator=(variable const &rhs)
    {
        variable tmp(rhs);
        std::swap(m_left_range, tmp.m_left_range);
        std::swap(m_right_range, tmp.m_right_range);
        std::swap(m_name, tmp.m_name);
        std::swap(m_sets, tmp.m_sets);
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    ~variable()
    {
        auto it = m_sets.begin();
        for(; it != m_sets.end(); ++it)
            delete it->second;
    }

    /////////////////////////////////////////////////
    /// @brief Add or modify a fuzzy set
    ///
    /// @param[in] name - The set name
    /// @param[in] set - The fuzzy set
    /////////////////////////////////////////////////
    void operator()(std::string const &name, set::abstract_set const &set)
    {
        if(m_sets.count(name) > 0)
            delete m_sets[name];
        m_sets[name] = set.clone();
        m_sets[name]->set_name(name);
        m_sets[name]->set_variable(m_name);
    }

    /////////////////////////////////////////////////
    /// @brief Get a fuzzy set
    ///
    /// @param[in] name - The set name
    /// @return the fuzzy set
    /////////////////////////////////////////////////
    set::abstract_set const &operator()(std::string const &name) const
    {
        auto it = m_sets.find(name);
        return *it->second;
    }

    /////////////////////////////////////////////////
    /// @brief Fuzzify the variable
    ///
    /// @param[in] crisp - crisp value
    /// @return the result manifold
    /////////////////////////////////////////////////
    manifold operator()(float crisp) const
    {
        std::map<std::string, manifold::set_manifold> sets;
        auto it = m_sets.begin();
        if(crisp >= m_left_range && crisp <= m_right_range)
        {
            for(; it != m_sets.end(); ++it)
                sets[it->first] = {it->second->membership(crisp),
                                   it->second->representative()};
        }
        else
        {
            for(; it != m_sets.end(); ++it)
                sets[it->first] = {0.f, it->second->representative()};
        }
        return {m_name, m_left_range, m_right_range, crisp, sets};
    }

private:

    // data members
    float m_left_range;
    float m_right_range;
    std::string m_name;
    std::map<std::string, set::abstract_set*> m_sets;

}; // class variable
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_VARIABLE_HPP
