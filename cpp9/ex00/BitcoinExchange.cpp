#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	if (!isCSVParsed("data.csv"))
		std::cerr << "Error: data file is missing." << std::endl;
}
BitcoinExchange::BitcoinExchange(const std::string &dataFile)
{
	if (!isCSVParsed(dataFile))
		std::cerr << "Error: data file " << dataFile << " is missing." << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : m_data(other.m_data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		m_data = other.m_data;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

std::pair<std::string, float> BitcoinExchange::GetDateAndRate(const std::string &line)
{
	size_t comma = line.find(',');

	if (comma == std::string::npos)
		return {"", 0};

	std::string date = line.substr(0, comma);
	std::string rate = line.substr(comma + 1);

	return {date, stof(rate)};
}

bool BitcoinExchange::isCSVParsed(const std::string &filename)
{
	std::ifstream file(filename);

	if (!file.is_open() || filename.empty())
		return false;

	std::string line = "";

	std::getline(file, line);
	while (std::getline(file, line))
	{
		auto dateAndRate = GetDateAndRate(line);
		m_data[dateAndRate.first] = dateAndRate.second;
	}

	file.close();
	return true;
}

std::string GetInfo(const std::string &line, size_t start, size_t end)
{
	std::string date = line.substr(start, end);
	return date;
}

bool isValidFloat(const std::string &value)
{
	int dotCount = 0;
	for( auto c : value)
	{
		if (c == '.') dotCount++;
		if (dotCount > 1) return false;
		if(!std::isdigit(c) || c != '.') return false;
	}
	return true;

}
bool isValidValue(const std::string &value)
{
	if (!isValidFloat(value))
		return false;
	try
	{
		float rate = std::stof(value);
		return (rate > 0 && rate <= 1000);
	}
	catch (...)
	{
		return false;
	}
}

bool isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string yearS = date.substr(0, 4);
	std::string monthS = date.substr(5, 2);
	std::string dayS = date.substr(8, 2);

	if (!std::all_of(yearS.begin(), yearS.end(), ::isdigit) ||
		!std::all_of(monthS.begin(), monthS.end(), ::isdigit) ||
		!std::all_of(dayS.begin(), dayS.end(), ::isdigit))
		return false;

	int year = stoi(yearS);
	int month = stoi(monthS);
	int day = stoi(dayS);

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	std::map<int, int> daysInMonth =
		{{1, 31}, {2, 28}, {3, 31},
    	{4, 30}, {5, 31}, {6, 30},
    	{7, 31}, {8, 31}, {9, 30},
    	{10, 31}, {11, 30}, {12, 31}};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[2] = 29;

	return day <= daysInMonth[month];
}

std::string BitcoinExchange::findClosestDate(const std::string& date)
{
	 auto it = m_data.lower_bound(date);

    if (it == m_data.begin() && it->first != date)
        return "";

    if (it != m_data.end() && it->first == date)
        return it->first;

    if (it != m_data.begin())
        --it;

    return it->first;	 
}
bool BitcoinExchange::isInputProcessed(const std::string &filename)
{
	std::ifstream file(filename);

	if (!file.is_open() || filename.empty())
		return false;

	std::string line = "";

	std::getline(file, line);
	if (line != "date | value")
		std::cerr << "Error: bad input => " << line << std::endl;

	while (std::getline(file, line))
	{
		if (line.empty())continue;		

		size_t pipePos = line.find('|');

		if (pipePos == std::string::npos)
			{std::cerr << "Error: bad input => " << line << std::endl;continue;}

		size_t pipePos2 = line.find('|', pipePos + 1);

		if (pipePos2 != std::string::npos)
			{std::cerr << "Error: bad input => " << line << std::endl;continue;}

		std::string date = GetInfo(line, 0, pipePos - 1);
		std::string value = GetInfo(line, pipePos + 1, line.find('\n') - 1);

		if (date.empty() || value.empty()|| !isValidDate(date) ||!isValidValue(value))
			{std::cerr << "Error: bad input => " << line << std::endl;continue;}


		std::string closestDate = findClosestDate(date);
		float exchangeRate = m_data[closestDate];
        float result = value * exchangeRate;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
	}

	file.close();
	return true;
}
