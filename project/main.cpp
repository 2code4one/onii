#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::settings settings(onii::settings::format::ini);

    settings.read("test/settings.ini");
    settings.debug();

    std::cout << std::endl;
    settings.write("test/settings.copy.ini");
    settings.read("test/settings.copy.ini");
    settings.debug();

    std::cout << std::endl;

    return 0;
}
