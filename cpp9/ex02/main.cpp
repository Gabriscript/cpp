#include "PmergeMe.hpp"
int main()
{
    std::vector<int> arr = {5, 9, 12, 2, 1, 4, 22, 6};
    
    PmergeMe pmergeme;
    arr = pmergeme.fordJohnsonSort(arr);

    
    pmergeme.printContainer(arr);
    return 0;
}