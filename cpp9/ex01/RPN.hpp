#pragma once
#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
public:
	RPN();
	RPN(const RPN& other);
	RPN &operator=(const RPN& other);
	~RPN();
	
	std::stack<int> m_stack;
	bool  isParsed(const std::string &av);
};

