#pragma once
#include <algorithm>
#include <stdexcept>
#include <vector>

class Span
{
private:
    unsigned int m_size;
    std::vector<int>	m_numbers;


    Span();
public:
    Span(unsigned int N);
    Span(const Span& other);
	Span& operator=(const Span& other);
    ~Span();

    void addnumber(int num);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;



    // Fill all elements in the numbers vector with the value 35
    //fill(numbers.begin(), numbers.end(), 35);
};


