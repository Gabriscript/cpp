#pragma once
#include <iostream>
#include<limits>
#include <string>
#include <array>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &other);
};



bool my_isprint(char ch);
bool IsPseudo(const std::string &input);
