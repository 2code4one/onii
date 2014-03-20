#ifndef ONII_AI_FUZZY_MANIFOLD_HPP
#define ONII_AI_FUZZY_MANIFOLD_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/manifold.hpp
/////////////////////////////////////////////////

#include <map>
#include <string>

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
/// @class manifold
/// @brief Fuzzy manifold
/////////////////////////////////////////////////
class manifold
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] variable_name - variable name
    /// @param[in] set_values - set values
    /// @remarks manifold is not intended to be created by user.
    ///          See onii::ai::fuzzy::variable::operator()(float)
    /////////////////////////////////////////////////
    manifold(std::string const &variable_name,
             std::map<std::string, float> const &set_values) :
        m_variable_name(variable_name),
        m_set_values(set_values)
    {}

    /////////////////////////////////////////////////
    /// @brief Get the variable name
    ///
    /// @return The variable name
    /////////////////////////////////////////////////
    std::string const &variable() const
    {
        return m_variable_name;
    }

    /////////////////////////////////////////////////
    /// @brief Get the set value
    ///
    /// @param[in] set_name - the set name
    /// @return The set value
    /////////////////////////////////////////////////
    float set(std::string const &set_name) const
    {
        auto it = m_set_values.find(set_name);
        return it->second;
    }

private:

    std::string m_variable_name;
    std::map<std::string, float> m_set_values;
}; // class manifold
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_MANIFOLD_HPP
