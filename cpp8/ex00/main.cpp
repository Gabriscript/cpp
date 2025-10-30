#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>

int main()
{
    std::vector<int> numbersV = {1, 7, 3, 5, 9, 2};
    std::list<int> numbersL = {1, 7, 3, 5, 9, 2};
    std::deque<int> numbersD = {1, 7, 3, 5, 9, 2};
    std::array<int, 6> numbersA = {1, 7, 3, 5, 9, 2};


    std::cout << "\t########## VECTOR ##############" << std::endl;
    std::cout<< "\n";
    std::cout << "========= Success ==============" << std::endl;
    std::cout<< "\n";
    try
    {
        auto number = easyfind(numbersV, 7);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }

    std::cout << "========= Error ==============" << std::endl;
    std::cout<< "\n";
    

    try
    {
        auto number = easyfind(numbersV, 10);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }


    std::cout << "\t########## LIST ##############" << std::endl;
    std::cout<< "\n";
    std::cout << "========= Success ==============" << std::endl;
    std::cout<< "\n";
    try
    {
        auto number = easyfind(numbersL, 2);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }

    std::cout << "========= Error ==============" << std::endl;
    std::cout<< "\n";
    try
    {
        auto number = easyfind(numbersL, -3);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }


    std::cout << "\t########## DEQUE ##############" << std::endl;
    std::cout<< "\n";
    std::cout << "========= Success ==============" << std::endl;
    std::cout<< "\n";

    try
    {
        auto number = easyfind(numbersD, 9);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }
    std::cout << "========= Error ==============" << std::endl;
    std::cout<< "\n";

    try
    {
        auto number = easyfind(numbersD, 55);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }


    std::cout << "\t########## ARRAY ##############" << std::endl;
    std::cout<< "\n";
    std::cout << "========= Success ==============" << std::endl;
    std::cout<< "\n";
    try
    {
        auto number = easyfind(numbersA, 1);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }
    std::cout << "========= Error ==============" << std::endl;
    std::cout<< "\n";

    try
    {
        auto number = easyfind(numbersA, 20000);
        std::cout << "Found: " << *number << std::endl;
        std::cout<< "\n";
    }
    catch(const std::exception& e){
        std::cout << "Exception: " <<  e.what() << std::endl;
        std::cout<< "\n";
    }



    return 0;
}