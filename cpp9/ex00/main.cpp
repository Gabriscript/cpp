#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{	
	if (ac != 2)
        return std::cerr << "Error: 1 file is requierd as argumeent" << std::endl, 1;

		try
		{
			BitcoinExchange btc;

			if (!btc.isInputProcessed(av[1]))
				return 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
		
	return 0;
}