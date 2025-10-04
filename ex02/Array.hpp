#pragma once
#include <stdexcept>
template <typename T>
class Array
{
private:
    unsigned int m_size;
    T* m_elements;
    
public:
    Array();
    Array(unsigned int size);
    Array(const Array &size);
    Array &operator=(const Array &other);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    ~Array();

    unsigned int size() const;
};

#include "Array.tpp"
