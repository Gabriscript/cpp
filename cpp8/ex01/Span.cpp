#include "Span.hpp"

Span::Span(unsigned int N) : m_size(N) {}
Span::Span(const Span &other) : m_size(other.m_size), m_numbers(other.m_numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		m_size = other.m_size;
		m_numbers = other.m_numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (m_numbers.size() >= m_size)
		throw std::runtime_error("Can't add more numbers");
	m_numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	if (m_numbers.size() < 2)
		throw std::runtime_error("There must be 2 elements at least");
	std::vector<int> copiedNumbers(m_numbers.size());
	std::partial_sort_copy(m_numbers.begin(), m_numbers.end(), copiedNumbers.begin(), copiedNumbers.end());

	unsigned int span = std::abs(copiedNumbers[0] - copiedNumbers[1]);

	for (unsigned int i = 1; i < copiedNumbers.size() - 1; i++)
	{
		unsigned int tmp = std::abs(copiedNumbers[i + 1] - copiedNumbers[i]);
		if (tmp < span)
			span = tmp;
	}
	return span;
}

unsigned int Span::longestSpan() const
{
	if (m_numbers.size() < 2)
		throw std::runtime_error("There must be 2 elements at least");
	auto span = std::minmax_element(m_numbers.begin(), m_numbers.end());
	return std::abs(*span.first - *span.second);
}