#include "BitcoinExchange.hpp"

    BitcoinExchange::BitcoinExchange()
	{
		if (!isParsed("data.csv")) std::cerr << "Error: data file is missing." << std::endl;

	}
    BitcoinExchange::BitcoinExchange(const std::string& dataFile)
	{
		if (!isParsed(dataFile)) std::cerr << "Error: data file "<<  dataFile << " is missing." << std::endl;
	}
    BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m_data(other.m_data){}
    BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
	{
		if (this != &other)
			m_data = other.m_data;
		return *this;
	}
    BitcoinExchange::~BitcoinExchange()	{} 
	
	static std::pair<std::string, float> GetDateAndRate(const std::string &line)
	{
		size_t comma = line.find(',');

		if (comma == std::string::npos) return {"", 0 };

		std::string date = line.substr(0,comma);
		std::string rate = line.substr(comma + 1);
		
		return {date, stof(rate)};
	}
	static bool isParsed(const std::string& filename)
	{
		std::ifstream file(filename);

		if (!file.is_open() || filename.empty()) return false;
			
		std::istringstream iss(filename);	
		std::string line = "";

		std::getline(iss, line);
		while (std::getline(iss, line))
		{
			GetDateAndRate(line);

		}



	}