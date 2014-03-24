#ifndef ONII_AI_FUZZY_VARIABLE_HPP
#define ONII_AI_FUZZY_VARIABLE_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/variable.hpp
/////////////////////////////////////////////////

#include <map>
#include <string>
#include "set/abstract_set.hpp"

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
    /// @struct manifold
    /// @brief Fuzzy variable manifold
    /////////////////////////////////////////////////
    struct manifold
    {
        /////////////////////////////////////////////////
        /// @struct set_manifold
        /// @brief Fuzzy set manifold
        /////////////////////////////////////////////////
        struct set_manifold
        {
            float membership;     ///< Set membership value
            float representative; ///< Set representative value

        }; // struct set_manifold

        std::string variable;     ///< Variable name
        float left_range;         ///< Variable min range
        float right_range;        ///< Variable max range
        std::map<std::string, set_manifold> sets; ///< Variable sets

    }; // struct manifold

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
        m_left_range = rhs.m_left_range;
        m_right_range = rhs.m_right_range;
        m_name = rhs.m_name;
        auto it = m_sets.begin();
        for(; it != m_sets.end(); ++it)
            delete it->second;
        m_sets.clear();
        auto it2 = rhs.m_sets.cbegin();
        for(; it2 != rhs.m_sets.cend(); ++it)
            m_sets[it2->first] = it2->second->clone();
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
        return {m_name, m_left_range, m_right_range, sets};
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
