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

static double calculate(double first, double second, char op)
{
    switch (op)
    {
        case '+': return second + first;
        case '-': return second - first;
        case '*': return second * first;
        case '/': return second / first;
        default: return 0.0;
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

			double first = m_stack.top(); m_stack.pop();
			double second = m_stack.top(); m_stack.pop();

			if (token == "/" && first == 0.0)
				return std::cerr << "Error"<< std::endl, false;

			m_stack.push(calculate(first, second, token[0]));
		}
		else
		{
			if (token.length() != 1 || !std::isdigit(static_cast<unsigned char>(token[0])))
				return std::cerr << "Error" << std::endl, false;

			double val = static_cast<double>(token[0] - '0');
			m_stack.push(val);
		}
	}
    if (m_stack.size() != 1)
        {return std::cerr << "Error"<< std::endl, false;}

	std::cout << std::fixed << std::setprecision(2) << m_stack.top() << std::endl;
    
	return true;
}

