#ifndef ONII_AI_FUZZY_SET_ABSTRACT_SET_HPP
#define ONII_AI_FUZZY_SET_ABSTRACT_SET_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/set/abstract_set.hpp
/////////////////////////////////////////////////

#include <string>
#include <vector>
#include "../manifold.hpp"

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
/// @class abstract_set
/// @brief Base class for fuzzy set
/////////////////////////////////////////////////
class abstract_set
{
public:

    /////////////////////////////////////////////////
    /// @brief Default constructor
    /////////////////////////////////////////////////
    abstract_set() :
        m_name(),
        m_variable()
    {}

    /////////////////////////////////////////////////
    /// @brief Virtual destructor
    /////////////////////////////////////////////////
    virtual ~abstract_set()
    {}

    /////////////////////////////////////////////////
    /// @brief Clone idiom
    ///
    /// @return A dynamic clone of the current instance
    /////////////////////////////////////////////////
    virtual abstract_set *clone() const = 0;

    /////////////////////////////////////////////////
    /// @brief Get the degree of membership
    ///
    /// @param[in] crisp - crisp value
    /// @return The degree of membership of crisp
    /// @remarks The degree of membership is a value between 0 and 1
    /////////////////////////////////////////////////
    virtual float membership(float crisp) const = 0;

    /////////////////////////////////////////////////
    /// @brief Get the degree of membership
    ///
    /// @param[in] m - list of manifolds
    /// @return The degree of membership of crisp into manifolds
    /// @remarks The degree of membership is a value between 0 and 1
    /////////////////////////////////////////////////
    virtual float membership(std::vector<manifold> const &m) const
    {
        for(unsigned int i = 0; i < m.size(); ++i)
        {
            if(m[i].variable == variable())
            {
                auto it = m[i].sets.find(name());
                return it->second.membership;
            }
        }
        return -1.f;
    }

    /////////////////////////////////////////////////
    /// @brief Get the representative value
    ///
    /// @return The representative value of the set
    /// @remarks This is for the max_av defuzzification
    /////////////////////////////////////////////////
    virtual float representative() const = 0;

    /////////////////////////////////////////////////
    /// @brief Set the set name
    ///
    /// @param[in] name_ - the set name
    /////////////////////////////////////////////////
    void set_name(std::string const &name_)
    {
        m_name = name_;
    }

    /////////////////////////////////////////////////
    /// @brief Get the set name
    ///
    /// @return The set name, if any
    /////////////////////////////////////////////////
    std::string const &name() const
    {
        return m_name;
    }

    /////////////////////////////////////////////////
    /// @brief Set the variable name
    ///
    /// @param[in] variable_ - the variable name
    /////////////////////////////////////////////////
    void set_variable(std::string const &variable_)
    {
        m_variable = variable_;
    }

    /////////////////////////////////////////////////
    /// @brief Get the variable name
    ///
    /// @return The variable name, if any
    /////////////////////////////////////////////////
    std::string const &variable() const
    {
        return m_variable;
    }

private:

    // data member
    std::string m_name;
    std::string m_variable;

}; // class abstract_set
} // namespace set
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_SET_ABSTRACT_SET_HPP
