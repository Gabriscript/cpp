#pragma once
#include "Array.hpp"
template <typename T>
Array<T>::Array() : m_size(0) , m_elements(nullptr)
{
}
template <typename T>
Array<T>::Array(unsigned int size) : m_size(size)
{
    m_elements = (size) ?  new T[size] : nullptr;
}
template <typename T>
Array<T>::Array(const Array &other)
{
    m_size = other.m_size;

    m_elements = (other.m_size) ? new T[m_size] : nullptr;

    for (unsigned int i = 0; i < m_size; i++)
        m_elements[i] = other.m_elements[i]; 
}
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this == &other)
        return *this;
    delete[] m_elements;

    m_size = other.m_size;

    m_elements = (other.m_size) ? new T[m_size] : nullptr;

    for (unsigned int i = 0; i < m_size; i++)
        m_elements[i] = other.m_elements[i];

    return *this;
    
}
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= m_size)
        throw std::out_of_range("Index out of bounds");
    return m_elements[index];
}
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= m_size)
        throw std::out_of_range("Index out of bounds");
    return m_elements[index];
}
template <typename T>
Array<T>::~Array()
{
    if (m_elements)
    delete [] m_elements;
}
template <typename T>
unsigned int Array<T>::size() const
{
    return m_size;
}