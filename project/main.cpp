#include <iostream>
#include "onii/onii.hpp"

int main()
{
    const int round = 10000000;
    onii::physic::unit::time time;

    {
        onii::core::scoped_timer scoped_timer(time);
        for(int i = 0; i < round; ++i)
            onii::core::random<float>();
    }
    std::cout << "float: " << time.ms() << " ms" << std::endl;

    {
        onii::core::scoped_timer scoped_timer(time);
        for(int i = 0; i < round; ++i)
            onii::core::random<int>();
    }
    std::cout << "int: " << time.ms() << " ms" << std::endl;

    onii::core::timer timer;
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.stop();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.start();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.start();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.stop();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.start();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.start();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;
    timer.stop();
    onii::core::sleep(1);
    std::cout << timer.elapsed().s() << std::endl;

    std::cout << "total time: " << onii::core::global_timer::elapsed().s() << " s" << std::endl;

    return 0;
}
