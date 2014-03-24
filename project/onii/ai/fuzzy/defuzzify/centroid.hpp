#ifndef ONII_AI_FUZZY_DEFUZZIFY_CENTROID_HPP
#define ONII_AI_FUZZY_DEFUZZIFY_CENTROID_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fuzzy/defuzzify/centroid.hpp
/////////////////////////////////////////////////

#include <algorithm>
#include "../variable.hpp"

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
/// @namespace onii::ai::fuzzy::defuzzify
/////////////////////////////////////////////////
namespace defuzzify
{
/////////////////////////////////////////////////
/// @brief Centroid defuzzification
///
/// @param[in] m - the variable manifold
/// @param[in] var - the manifold's variable
/// @param[in] samples - how many samples to use
/// @return a crisp value of the manifold
/////////////////////////////////////////////////
float centroid(variable::manifold const &m, variable const &var, unsigned int samples = 20)
{
    float nom = 0.f;
    float den = 0.f;
    float gap = (m.right_range - m.left_range) / samples;
    for(unsigned int i = 0; i <= samples; ++i)
    {
        float sum = 0.f;
        float value = m.left_range + i * gap;
        auto it = m.sets.cbegin();
        for(; it != m.sets.cend(); ++it)
            sum += std::min(it->second.membership, var(it->first).membership(value));
        nom += sum * value;
        den += sum;
    }
    return nom / den;
}
} // namespace defuzzify
} // namespace fuzzy
} // namespace ai
} // namespace onii

#endif // ONII_AI_FUZZY_DEFUZZIFY_CENTROID_HPP
