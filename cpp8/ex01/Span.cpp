#include "Span.hpp"


Span::Span(unsigned int N) : m_numbers(N){}
Span::Span(const Span& other) : 
m_size(other.m_size), m_numbers(other.m_numbers){}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		m_size = other.m_size;
		m_numbers = other.m_numbers;
	}
	return *this;
}

Span::~Span(){}

void Span::addnumber(int num)
{
    if (m_numbers.size() > m_size)
        throw std::runtime_error("Can't add more numbers");
    m_numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if (m_numbers.size() < 2)
		throw std::runtime_error("There must be 2 elements at least");
    std::vector<int> copiedNumbers(m_numbers.size());
   std::partial_sort_copy(m_numbers.begin(), m_numbers.end(), copiedNumbers.begin(), copiedNumbers.end());

   unsigned int span = abs(copiedNumbers[0] - copiedNumbers[1]);
   //for(auto it : copiedNumbers)
        // TODO : compare  span with tmp check with has less distance
    
}
unsigned int Span::longestSpan() const
{
    if (m_numbers.size() < 2)
		throw std::runtime_error("There must be 2 elements at least");
    auto span = std::minmax_element(m_numbers.begin(), m_numbers.end());
    return abs(span.first - span.second);
}