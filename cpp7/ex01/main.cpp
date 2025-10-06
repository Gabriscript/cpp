#include "iter.hpp"
#include <iostream>

void plusFive(int &x)
{
    x += 5;
}

template <typename T>
void consoleWriteline(const T &t)
{
    std::cout << t << " ";
}

int main()
{
    int numbers[4] = {0, 1, 2, 3};
    std::string words[3] = {"We", "❤️", "C++"};

    std::cout << "\n########### Integer Array ###########\n" << std::endl;
    iter(numbers, 4, consoleWriteline<int>);
    std::cout << "\n";

    iter(numbers, 4, plusFive);

    std::cout << "\n###### Integer Array plus 5 #########\n" << std::endl;
    iter(numbers, 4, consoleWriteline<int>);
    std::cout << "\n";

    std::cout << "\n########### String Array ###########\n" << std::endl;
    iter(words, 3, consoleWriteline<std::string>);
    std::cout << "\n" << std::endl;
}

