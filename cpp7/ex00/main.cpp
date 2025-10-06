#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 5;
	int b = 7;

	std::cout << "#######    DEAFAULT  #############\n"<< std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;

	swap(a,b);

	std::cout << "#######   SWAPPED   #############\n"<< std::endl;
	
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;

	std::cout << "#######  MIN  ###################\n"<< std::endl;

	std::cout << "min : " << min(a,b) << std::endl;
	

	std::cout << "#######  MAX  ###################\n"<< std::endl;

	std::cout << "max : " << max(a,b) << std::endl;



	return 0;
}