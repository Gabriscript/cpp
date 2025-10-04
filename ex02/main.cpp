#include "Array.hpp"
#include <iostream>

int main()
{

    std::cout << "\n################### DEFAULT ####################" << std::endl;

    Array<int> arr1(3);

    arr1[0] = 2;
    arr1[1] = 3;
    arr1[2] = 5;

    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << std::endl;
    std::cout << std::endl;
    std::cout << "################### COPY ####################" << std::endl;

    Array<int> arr2(arr1);
    std::cout << "index arr1[2] : " << arr1[2] << std::endl;
    std::cout << "index arr2[2] : " << arr2[2] << std::endl;

    arr2[2] = 1;

    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << std::endl;

    std::cout << "check index arr2[2] after change the value: " << arr2[2] << std::endl;

    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << std::endl;

    std::cout << std::endl;

    std::cout << "################### ASSIGNEMENT ####################" << std::endl;

    Array<int> arr3(3);
    arr3 = arr1;
    std::cout << "array 1" << std::endl;
    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << std::endl;

    std::cout << "array 3 = array 1" << std::endl;
    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr3[i] << std::endl;

    std::cout << "\n################### EMPTY ARRAY ####################" << std::endl;

    Array<int> emptyArr;
    std::cout << "Size of empty array: " << emptyArr.size() << std::endl;

    std::cout << "\n################### OUT OF RANGE ####################" << std::endl;
    try
    {
        arr1[10] = 42;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Catched: " << e.what() << std::endl;
    }

    std::cout << "\n################### CONST ACCESS ####################" << std::endl;

    const Array<int> constArr(arr1);
    std::cout << "constArr[0] = " << constArr[0] << std::endl;

    // constArr[0] = "42";  // compilation ERROR

    std::cout << "\n################### STRING ####################" << std::endl;
    Array<std::string> stringArr(3);
    stringArr[0] = "We ";
    stringArr[1] = " ❤️ ";
    stringArr[2] = " C++";

    for (unsigned int i = 0; i < stringArr.size(); i++)
        std::cout << stringArr[i];

    std::cout << std::endl;
    return 0;
}