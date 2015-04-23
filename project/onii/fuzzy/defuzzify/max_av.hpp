#ifndef ONII_FUZZY_DEFUZZIFY_MAX_AV_HPP
#define ONII_FUZZY_DEFUZZIFY_MAX_AV_HPP

/////////////////////////////////////////////////
/// @file onii/fuzzy/defuzzify/max_av.hpp
/////////////////////////////////////////////////

#include "../manifold.hpp"

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
/// @namespace onii::fuzzy::defuzzify
/////////////////////////////////////////////////
namespace defuzzify
{
/////////////////////////////////////////////////
/// @brief Average of maxima defuzzification
///
/// @param[in] m - the variable manifold
/// @return a crisp value of the manifold
/////////////////////////////////////////////////
float max_av(manifold const &m)
{
    float nom = 0.f;
    float den = 0.f;
    auto it = m.sets.cbegin();
    for(; it != m.sets.cend(); ++it)
    {
        nom += it->second.membership * it->second.representative;
        den += it->second.membership;
    }
    return !equal(den, 0.f) ? nom / den : m.left_range;
}
} // namespace defuzzify
} // namespace fuzzy
} // namespace onii

#endif // ONII_FUZZY_DEFUZZIFY_MAX_AV_HPP
