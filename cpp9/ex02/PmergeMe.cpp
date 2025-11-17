#include "PmergeMe.hpp"

// J(n) = J(n-1) + 2*J(n-2)

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
void insertionSort(Container &arr)
{
    int len = arr.size();
    for (int i = 1; i <= len; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
std::vector<int> generateJacobsthal(int n)
{
    if (n <= 0)
        return {};

    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(1);

    while (jacob.back() < n)
    {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}

template <typename Container>
Container PmergeMe::fordJohnsonSort(Container arr)
{
    int len = arr.size();
    if (len <= 1)
        return arr;

    if (arr.size() == 2)
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

        (first > second) ? couples.push_back({first, second}) : couples.push_back({second, first});
    }

    Container mainChain;
    for (auto &pair : couples)
        mainChain.push_back(pair.first);

     mainChain = fordJohnsonSort(mainChain);

    std::vector<int> lefts;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = 0; j < couples.size(); j++)
        {
            if (couples[j].first == mainChain[i])
            {
                lefts.push_back(couples[j].second);
                break;
            }
        }
    }

    Container result = mainChain;

    // TODO: use jacobsthal sequence to insert lefts into result
    if (!lefts.empty())
    {
        auto pos = std::lower_bound(result.begin(), result.end(), lefts[0]);
        result.insert(pos, lefts[0]);
    }

    std::vector<int> jac = generateJacobsthal(lefts.size());
    for (size_t i = 1; i < lefts.size(); i++)
    {
        if (!inserted[i])
        {
            auto pos = std::lower_bound(result.begin(), result.end(), lefts[i]);
            result.insert(pos, lefts[i]);
        }
        if (extra != -1)
        {
            auto pos = std::lower_bound(result.begin(), result.end(), extra);
            result.insert(pos, extra);
        }
    }
        return result;
}

    template std::vector<int> PmergeMe::fordJohnsonSort<std::vector<int>>(std::vector<int> arr);
    template std::deque<int> PmergeMe::fordJohnsonSort<std::deque<int>>(std::deque<int> arr);
    template void PmergeMe::printContainer<std::vector<int>>(const std::vector<int> &arr);
    template void PmergeMe::printContainer<std::deque<int>>(const std::deque<int> &arr);