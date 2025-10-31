#pragma once
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>

class Span
{
private:
	unsigned int m_size;
	std::vector<int> m_numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int num);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		unsigned int distance = std::distance(begin, end);
		if (m_numbers.size() + distance > m_size)
			throw std::runtime_error("too many elements");
		m_numbers.insert(m_numbers.end(), begin, end);
	}
};
