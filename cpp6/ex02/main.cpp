#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>





Base* generate()
{
    int r = rand() % 3;
    return r == 0 ? (Base*)new A() : r == 1 ? (Base*)new B() : (Base*)new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not recognized" << std::endl;
}
void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::bad_cast&){}
		try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::bad_cast&){}
		try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::bad_cast&){}
	std::cout << "Not recognize" << std::endl;
	

}

int main()
{
	srand(time(0));
	Base *bases[] = {new A(), new B, new C};


	std::cout << "Reference A:\t" << std::endl;
	identify(bases[0]);
	std::cout << "Reference B:\t" << std::endl;
	identify(bases[1]);
	std::cout << "Reference C:\t" << std::endl;
	identify(bases[2]);

	std::cout << "Pointer A:\t" << std::endl;
	identify(*bases[0]);
	std::cout << "Pointer B:\t" << std::endl;
	identify(*bases[1]);
	std::cout << "Pointer C:\t" << std::endl;
	identify(*bases[2]);

	for (auto ptr : bases) delete ptr;


	for (size_t i = 1; i <= 10; i++)
	{
		Base *random = generate();
	
		std::cout << "Base index " << i << ":\t" << std::endl;

		std::cout << "Reference :\t" << std::endl;
		identify(random);
		std::cout << "Pointer :\t" << std::endl;
		identify(*random);
	
		delete random;
	}
}
