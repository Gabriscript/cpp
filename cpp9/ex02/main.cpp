#include "PmergeMe.hpp"

template<typename Container>
bool isSorted(const Container& arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1] > arr[i])
			return false;
	}
	return true;
}

int main(int ac, char **av)
{
    if (ac < 2)
		return std::cerr << "An argument is required" << std::endl, 1;
    
	std::string str = "";
	for (int i = 1; i < ac; i++)
	{
		str += av[i];
		if (std::isdigit(str.back()))
			str += ' ';
		else
			 return std::cerr << "Error: Invalid character in input" << std::endl, 1;
	}

	try {
		std::istringstream iss(str);
		std::vector<int> arrayVec;
		std::deque<int> arrayDeque;
		std::string token;
		while (iss >> token)
		{

			for (char c : token)
				if (!std::isdigit(static_cast<unsigned char>(c)))
					throw std::invalid_argument("Error: Invalid character in input");

			try {
				long long val = std::stoll(token);
				if (val < 0)
					throw std::invalid_argument("Error: only positive numbers are allowed");
				if (val > static_cast<long long>(std::numeric_limits<int>::max()))
					throw std::out_of_range("Error: number exceeds maximum integer value");

				if (std::find(arrayVec.begin(), arrayVec.end(), static_cast<int>(val)) != arrayVec.end())
					throw std::invalid_argument("Error: duplicate numbers are not allowed");

				arrayVec.push_back(static_cast<int>(val));
				arrayDeque.push_back(static_cast<int>(val));
			} catch (const std::invalid_argument &e) {
				throw std::invalid_argument(std::string("Error: invalid number -> ") + token);
			} catch (const std::out_of_range &e) {
				throw std::invalid_argument("Error: number exceeds maximum integer value");
			}
		}
		PmergeMe pmergeme;

		auto start_vec = std::chrono::high_resolution_clock::now();
		arrayVec = pmergeme.fordJohnsonSort(arrayVec);
		auto end_vec = std::chrono::high_resolution_clock::now();

		auto start_deque = std::chrono::high_resolution_clock::now();
		arrayDeque = pmergeme.fordJohnsonSort(arrayDeque);
		auto end_deque = std::chrono::high_resolution_clock::now();

		std::cout << "Sorted arrays: " << std::endl;
		pmergeme.printContainer(arrayVec);
		pmergeme.printContainer(arrayDeque);

		std::cout << "Time taken (vector): " << std::chrono::duration_cast<std::chrono::microseconds>(end_vec - start_vec).count() << " microseconds" << std::endl;
		std::cout << "Time taken (deque): " << std::chrono::duration_cast<std::chrono::microseconds>(end_deque - start_deque).count() << " microseconds" << std::endl;

		if (!isSorted(arrayVec) || !isSorted(arrayDeque))
			return std::cerr << "Error: Sorting failed" << std::endl, 1;
	} catch (const std::exception &e) {

		return std::cerr << e.what() << std::endl,1;
	} 

    return 0;
}