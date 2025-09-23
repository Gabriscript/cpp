#include"Bureaucrat.hpp"

int main()
{
	Bureaucrat mario;
	std::cout << mario << std::endl;
	Bureaucrat luigi("Luigi", 100);

	std::cout << "\n" << std::endl;

	std::cout << "Trying Yoshi grade too low.." << std::endl;
	try
	{
		Bureaucrat yoshi("Yoshi",500);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nTrying Peach grade too high.." << std::endl;
	try
	{
		Bureaucrat Peach("Peach",-2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nTrying to increase Bowser grade too high.." << std::endl;
	try
	{
		Bureaucrat bowser("Bowser",3);
		bowser.Increase(-5);
		std::cout << bowser << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}