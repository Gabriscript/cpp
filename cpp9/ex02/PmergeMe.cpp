#include "PmergeMe.hpp"

std::vector<int> PmergeMe::generateJacobsthal(int n)
{
    std::vector<int> jacob;
    jacob.push_back(0); 
    jacob.push_back(1);  
    
    while (jacob.back() < n + 10) 
    {
        int sz = jacob.size();
        int next = jacob[sz - 1] + 2 * jacob[sz - 2];
        jacob.push_back(next);
    }
    return jacob;
}


std::vector<int> PmergeMe::generateJacobsthalOrder(int n)
{
    if (n <= 0) return {};
    
    std::vector<int> jacob = generateJacobsthal(n + 10);
    std::vector<int> order;
    

    order.push_back(0);
    if (n == 1) return order;
    
    int jacobIdx = 3; 
    
    while (order.size() < static_cast<size_t>(n))
    {
        int current = jacob[jacobIdx];
        int previous = jacob[jacobIdx - 1];
        

        for (int i = std::min(current, n); i > previous; i--)
            order.push_back(i - 1); 
    
        
        jacobIdx++;
    }
    
    return order;
}


