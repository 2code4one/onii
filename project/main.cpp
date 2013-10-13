#include <iostream>
#include "onii/onii.hpp"

#include <fstream>
#include <list>

int main()
{
    std::ofstream ofs("test.log");
    onii::log::debug::redirect(ofs);
    onii::log::info::redirect(onii::log::debug::stream());
    onii::log::debug("for") << "begin:";
    for(int i = 1; i < 6; ++i)
        onii::log::debug(1) << "i = " << i;
    onii::log::debug("for") << "EOF";
    onii::log::debug::active(false);
    onii::log::info::active(false);
    onii::log::info() << "not shown";
    onii::log::info::active(true);
    onii::log::info("list values") << onii::log::container(std::list<int>{1, 2, 3});

    return 0;
}
