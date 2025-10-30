#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    auto it = std::find(container.begin(), container.end(), value);
    
    return it != container.end() ? it : throw std::runtime_error("not found");
}



