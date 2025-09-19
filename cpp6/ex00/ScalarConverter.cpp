#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &input)
{
    std::string toChar = "impossible";
    int toInt = 0;
    float toFloat = 0;
    double toDouble = 0;
    bool intImpossible = false;

    if (IsPseudo(input))
        return;

    if (input.size() == 1 && my_isprint(input[0]) && !std::isdigit(input[0]))
    {
        toChar = "'";
        toChar += input[0];
        toChar += "'";
        toInt = static_cast<int>(input[0]);
        toFloat = static_cast<float>(input[0]);
        toDouble = static_cast<double>(input[0]);
    }
    else
    {
        try
        {
            if (input[input.length() - 1] == 'f')
            {
                toFloat = std::atof(&input[0]);
                toDouble = static_cast<double>(toFloat);
                toInt = static_cast<int>(toFloat);
            }
            else
            {
                if (input.find('.') != std::string::npos)
                {
                    toDouble = std::atof(&input[0]);
                    toFloat = static_cast<float>(toDouble);
                    toInt = static_cast<int>(toDouble);
                }
                else
                {
                    toInt = std::stoi(input);
                    toFloat = static_cast<float>(toInt);
                    toDouble = static_cast<double>(toInt);
                }
            }
            if (toInt >= 0 && toInt <= 255)
            {
                if (my_isprint(static_cast<char>(toInt)))
                {
                    toChar = "'";
                    toChar += static_cast<char>(toInt);
                    toChar += "'";
                }
                else
                    toChar = "Non displayable";
            }
        }
        catch (...)
        {
            intImpossible = true;
        }
    }

    std::cout << "char: " << toChar << std::endl;
    
    intImpossible ? 
                std::cout << "int: impossible" << std::endl :
                std::cout << "int: " << toInt << std::endl;
    
    std::cout << "float: ";
    (round(toFloat) == toFloat && !intImpossible) ?
                std::cout << toFloat << ".0f" << std::endl :
                std::cout << toFloat << "f" << std::endl;
    
    std::cout << "double: "; 
    (round(toDouble) == toDouble && !intImpossible) ?
                std::cout << toDouble << ".0" << std::endl :
                std::cout << toDouble << std::endl;
}