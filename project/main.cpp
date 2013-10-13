#include <iostream>
#include "onii/onii.hpp"

#include <vector>
#define VECTOR(type) do { std::vector<type> c

#include <map>
#define MAP(key, type) do { std::map<key, type> c

#define DO_TEST std::cout << onii::log::container(c) << std::endl; } while(false)

int main()
{
    VECTOR(int) = {1, 2, 3};
    DO_TEST;

    VECTOR(std::string) = {"salut", "ca", "va?"};
    DO_TEST;

    MAP(int, int) = {{1, 2}, {3, 4}};
    DO_TEST;

    MAP(int, std::string) = {{1, "salut"}, {2, "ca va?"}};
    DO_TEST;

    return 0;
}
