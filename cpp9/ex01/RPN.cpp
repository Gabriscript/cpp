#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) { *this = other; }

RPN &RPN::operator=(const RPN& other)
{ 
	if (this != &other)
		m_stack = other.m_stack;
	return *this;
}

RPN::~RPN() {}

static bool isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

static int calculate(int first, int second, char op) 
{
	switch (op)
	{
		case '+': return second + first;
		case '-': return second - first;
		case '*': return second * first;
		case '/': return second / first;
		default: return 0;
	}
}

bool RPN::isParsed(const std::string &av)
{
	std::istringstream iss(av);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (m_stack.size() < 2)
				return std::cerr << "Error"<< std::endl, false;

			int first = m_stack.top(); m_stack.pop();
			int second = m_stack.top(); m_stack.pop();

			if (token == "/" && first == 0)
				return std::cerr << "Error"<< std::endl, false;

			m_stack.push(calculate(first, second, token[0]));
		}
		else
		{
			for (char c : token)
				if (!std::isdigit(c))
					return std::cerr << "Error"<< std::endl, false;

			m_stack.push(std::stoi(token));
		}
	}
    if (m_stack.size() != 1)
        return std::cerr << "Error"<< std::endl, false;

    std::cout  << m_stack.top() << std::endl;
    
	return true;
}

