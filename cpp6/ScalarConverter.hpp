#pragma once
#include <iostream>
#include<limits>
#include <string>
#include <array>

std::array<std::string, 6> pseudoLiterals = {
    "+inff", "-inff", "nanf",
    "+inf", "-inf", "nan"
};

class ScalarConverter
{
private:
ScalarConverter();
ScalarConverter(const ScalarConverter &other);
ScalarConverter &operator=(const ScalarConverter &other);

public:
~ScalarConverter();
static void convert(std::string &other);
};



bool my_isprint(char ch);
bool IsPseudo(const std::string &input);
