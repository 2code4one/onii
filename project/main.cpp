#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::settings settings(onii::settings::format::ini);

    settings.read("test/settings.ini");
    settings.write("test/settings.copy.ini");

    std::string buf;
    std::ifstream ifs("test/settings.copy.ini");
    while(std::getline(ifs, buf))
        std::cout << buf << std::endl;

    return 0;
}
