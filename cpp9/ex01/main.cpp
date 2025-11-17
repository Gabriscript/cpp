#include "RPN.hpp"



int main(int ac,char **av)
{
	if (ac < 2)
		return std::cerr << "Error"<< std::endl, 1;
        
	RPN rpn;
	return (rpn.isParsed(av[1]));
}