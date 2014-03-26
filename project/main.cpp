#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::ai::fuzzy::variable desirability("Desirability", 0, 100);
    desirability("Undesirable", onii::ai::fuzzy::set::left_shoulder(0, 25, 50));
    desirability("Desirable", onii::ai::fuzzy::set::triangle(25, 50, 75));
    desirability("Very Desirable", onii::ai::fuzzy::set::right_shoulder(50, 75, 100));

    onii::ai::fuzzy::variable distance("Distance to Target", 0, 400);
    distance("Close", onii::ai::fuzzy::set::left_shoulder(0, 25, 150));
    distance("Medium", onii::ai::fuzzy::set::triangle(25, 150, 300));
    distance("Far", onii::ai::fuzzy::set::right_shoulder(150, 300, 400));

    onii::ai::fuzzy::variable ammo("Ammo Status", 0, 40);
    ammo("Low", onii::ai::fuzzy::set::left_shoulder(0, 0, 10));
    ammo("Okay", onii::ai::fuzzy::set::triangle(0, 10, 30));
    ammo("Loads", onii::ai::fuzzy::set::right_shoulder(10, 30, 40));

    onii::ai::fuzzy::rules rules(desirability);
    rules(distance("Far") & ammo("Loads"), "Desirable");
    rules(distance("Far") & ammo("Okay"), "Undesirable");
    rules(distance("Far") & ammo("Low"), "Undesirable");
    rules(distance("Medium") & ammo("Loads"), "Very Desirable");
    rules(distance("Medium") & ammo("Okay"), "Very Desirable");
    rules(distance("Medium") & ammo("Low"), "Desirable");
    rules(distance("Close") & ammo("Loads"), "Undesirable");
    rules(distance("Close") & ammo("Okay"), "Undesirable");
    rules(distance("Close") & ammo("Low"), "Undesirable");

    onii::ai::fuzzy::manifold m = rules({distance(200), ammo(8)});

    std::cout << "max_av -> "
              << onii::ai::fuzzy::defuzzify::max_av(m)
              << std::endl;
    std::cout << "centroid -> "
              << onii::ai::fuzzy::defuzzify::centroid(m, desirability)
              << std::endl;

    return 0;
}
