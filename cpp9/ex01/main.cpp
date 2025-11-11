#include "RPN.hpp"



int main(int ac,char **av)
{
	if (ac < 2)
		return std::cerr << "Error"<< std::endl, 1;
	
	std::string expression;

	for (int i = 1; i < ac; i++)
		expression += std::string(av[i]) + " ";
	
	RPN rpn;
	if(rpn.isParsed(expression))
		return std::cerr << rpn.m_stack.top() << std::endl, 0;
	else 
		return std::cerr << "Error"<< std::endl, 1;
}