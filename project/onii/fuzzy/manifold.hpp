#ifndef ONII_FUZZY_MANIFOLD_HPP
#define ONII_FUZZY_MANIFOLD_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/manifold.hpp
/////////////////////////////////////////////////

#include <map>
#include <string>

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
    float crisp;              ///< Crisp value
    std::map<std::string, set_manifold> sets; ///< Variable sets

}; // struct manifold
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_MANIFOLD_HPP
