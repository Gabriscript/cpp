#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{	
	if (ac != 2)
        return std::cerr << "Error: 1 file is requierd as argumeent" << std::endl, 1;

		try
		{
			BitcoinExchange btc;

			// if data.csv is not found or empty 
			// 	return error

			// if file is av[1] is empty or invalid
			// 	return error


		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		


	return 0;
}