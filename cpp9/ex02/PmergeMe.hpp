#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <chrono>

class PmergeMe
{
private:


public:
    PmergeMe() = default;
    ~PmergeMe() = default;
    PmergeMe(const PmergeMe &other) = default;
    PmergeMe &operator=(const PmergeMe &other) = default;

    template <typename Container>
    Container fordJohnsonSort(Container arr);

	template <typename Container>
	void printContainer(const Container &arr);

	std::vector<int> generateJacobsthal(int n);
	std::vector<int> generateJacobsthalOrder(int n);
};

#include "PmergeMe.tpp"