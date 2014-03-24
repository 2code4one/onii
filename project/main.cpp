#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::ai::fuzzy::variable desirability("Desirability", 0, 100);
    desirability("Undesirable", onii::ai::fuzzy::set::left_shoulder(0, 25, 50));
    desirability("Desirable", onii::ai::fuzzy::set::triangle(25, 50, 75));
    desirability("Very Desirable", onii::ai::fuzzy::set::right_shoulder(50, 75, 100));

    onii::ai::fuzzy::variable::manifold m = desirability(-1);
    m.sets["Undesirable"].membership = 0.33f;
    m.sets["Desirable"].membership = 0.2f;
    m.sets["Very Desirable"].membership = 0.67f;

    std::cout << m.variable << " "
              << m.left_range << " "
              << m.right_range << " "
              << m.sets["Undesirable"].membership << " "
              << m.sets["Desirable"].membership << " "
              << m.sets["Very Desirable"].membership << " "
              << m.sets["Undesirable"].representative << " "
              << m.sets["Desirable"].representative << " "
              << m.sets["Very Desirable"].representative << " "
              << std::endl;

    float max_av = onii::ai::fuzzy::defuzzify::max_av(m);
    std::cout << "max_av -> " << max_av << std::endl;

    float centroid = onii::ai::fuzzy::defuzzify::centroid(m, desirability);
    std::cout << "centroid -> " << centroid << std::endl;

    onii::timer timer;
    unsigned int max_av_count = 0;
    for(timer.restart(); timer.elapsed().s() < 1.f; ++max_av_count)
        float c = onii::ai::fuzzy::defuzzify::max_av(m);
    std::cout << "In 1s, max_av runs " << max_av_count << " times" << std::endl;
    unsigned int centroid_count = 0;
    for(timer.restart(); timer.elapsed().s() < 1.f; ++centroid_count)
        float c = onii::ai::fuzzy::defuzzify::centroid(m, desirability);
    std::cout << "In 1s, centroid runs " << centroid_count << " times" << std::endl;
    std::cout << "max_av is " << (max_av_count / centroid_count) << " times faster than centroid" << std::endl;

    return 0;
}
