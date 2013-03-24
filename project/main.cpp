#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::core::split_results results;

    results = onii::core::splitter("My name is Patrick.")
                    .by_separators(" .")
                    .remove_empty()
                    .results();

    for(auto it : results)
        std::cout << "-> \"" << it << "\"" << std::endl;

    return 0;
}
