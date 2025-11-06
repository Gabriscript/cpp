#pragma once
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <limits>

class BitcoinExchange
{
private:
	std::map<std::string, float> m_data;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &dataFile);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	std::pair<std::string, float> GetDateAndRate(const std::string &line);
	bool isCSVParsed(const std::string &filename);
	bool isInputProcessed(const std::string &filename);
	std::string findClosestDate(const std::string& date);
};
