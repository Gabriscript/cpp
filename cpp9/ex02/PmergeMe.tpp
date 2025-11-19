#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::printContainer(const Container &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}


template <typename Container>
Container PmergeMe::fordJohnsonSort(Container arr)
{
    int len = arr.size();
    if (len <= 1)
        return arr;

    if (len == 2)
    {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return arr;
    }


    int extra = -1;
    if (len % 2 != 0)
    {
        extra = arr[len - 1];
        arr.pop_back();
        len -= 1;
    }

  
    std::vector<std::pair<int, int>> couples;
    for (int i = 0; i < len; i += 2)
    {
        int first = arr[i];
        int second = arr[i + 1];
        couples.push_back(first > second ? 
            std::make_pair(first, second) : 
            std::make_pair(second, first));
    }

 
    Container winners;
    for (const auto &p : couples)
        winners.push_back(p.first);
    
    winners = fordJohnsonSort(winners);


    std::vector<std::pair<int, int>> sortedCouples;
    for (const auto &winner : winners)
    {
        for (const auto &couple : couples)
        {
            if (couple.first == winner)
            {
                sortedCouples.push_back(couple);
                break;
            }
        }
    }


    Container result;
    result.push_back(sortedCouples[0].second); 
    for (const auto &winner : winners)
        result.push_back(winner);


    std::vector<int> insertOrder = generateJacobsthalOrder(sortedCouples.size() - 1);

 
    for (int idx : insertOrder)
    {
        int actualIdx = idx + 1; 
        if (actualIdx >= static_cast<int>(sortedCouples.size()))
            continue;
            
        int loser = sortedCouples[actualIdx].second;
        int winner = sortedCouples[actualIdx].first;

  
        auto winnerPos = std::find(result.begin(), result.end(), winner);
        
 
        auto pos = std::lower_bound(result.begin(), winnerPos + 1, loser);
        result.insert(pos, loser);
    }

 	if (extra != -1)
    {
        auto pos = std::lower_bound(result.begin(), result.end(), extra);
        result.insert(pos, extra);
    }

    return result;
}

template std::vector<int> PmergeMe::fordJohnsonSort<std::vector<int>>(std::vector<int> arr);
template std::deque<int> PmergeMe::fordJohnsonSort<std::deque<int>>(std::deque<int> arr);
template void PmergeMe::printContainer<std::vector<int>>(const std::vector<int>& arr);
template void PmergeMe::printContainer<std::deque<int>>(const std::deque<int>& arr);