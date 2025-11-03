#pragma once
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include<iostream>


class BitcoinExchange
{
private:
	 std::map<std::string, float> m_data;

public:

    BitcoinExchange();
    BitcoinExchange(const std::string& dataFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange(); 
};

