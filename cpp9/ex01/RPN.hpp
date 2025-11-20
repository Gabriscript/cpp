#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <limits>
#include <iomanip>

class RPN
{
public:
	RPN();
	RPN(const RPN& other);
	RPN &operator=(const RPN& other);
	~RPN();
	
	std::stack<double> m_stack;
	bool  isParsed(const std::string &av);
};

