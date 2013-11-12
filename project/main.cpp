#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::settings settings(onii::settings::format::ini);

    settings.read("test/settings.ini");
    settings.write("test/settings.copy.ini");

    return 0;
}
