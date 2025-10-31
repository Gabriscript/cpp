#include "Span.hpp"
#include <iostream>

int main()
{

	std::cout << "\n\t######## SUBJECT ###########" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "Attempting to add a 6th element..." << std::endl;
		sp.addNumber(25);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\t######## EDGE & ERROR CASES ###########" << std::endl;

	std::cout << "======== only one element ==========" << std::endl;

	try
	{
		Span one = Span(1);
		one.addNumber(6);

		std::cout << one.shortestSpan() << std::endl;
		std::cout << one.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "======== all same number  ==========" << std::endl;
	try
	{
		Span same = Span(3);
		same.addNumber(6);
		same.addNumber(6);
		same.addNumber(6);

		std::cout << same.shortestSpan() << std::endl;
		std::cout << same.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "======== rangeative numbers  ==========" << std::endl;

	try
	{
		Span neg = Span(4);
		neg.addNumber(-6);
		neg.addNumber(-66);
		neg.addNumber(-42);
		neg.addNumber(-50);

		std::cout << neg.shortestSpan() << std::endl;
		std::cout << neg.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\t######## ADDRANGE ###########" << std::endl;

	try
	{
		Span range(15);
		range.addNumber(-6);
		range.addNumber(66);

		std::vector<int> vec = {2, 4, 6, 8, 10, 100, 14, 16, 18, 20, 11, 12, 13};
		range.addRange(vec.begin(), vec.end());

		std::cout << range.shortestSpan() << std::endl;
		std::cout << range.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}