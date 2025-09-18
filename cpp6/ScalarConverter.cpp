#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "constructor called" << std::endl;
}

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

ScalarConverter::~ScalarConverter()
{
    std::cout << "destructor called" << std::endl;
}

void ScalarConverter::convert(std::string &input)
{
    std::string toChar = "";
    int toInt = 0;
    float toFloat = 0;
    double toDouble = 0;

    if (IsPseudo(input))
        return;

    if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
    {

        toChar = input[0];
        toInt = static_cast<int>(input[0]);
        toFloat = static_cast<float>(input[0]);
        toDouble = static_cast<double>(input[0]);
    }
    else
    {
        toChar = "impossible";
        try
        {
            toInt = std::stoi(input);
            if (toInt >= 0 && toInt <= 255)
            {
                if (std::isprint(static_cast<unsigned char>(toInt))){
                   		toChar = "'";
		                toChar += static_cast<char>(toInt);
		                toChar += "'";}
                else
                    toChar = "Non displayable";
            }
        }
        catch (const std::out_of_range &)
        {
            toFloat = std::numeric_limits<float>::infinity();
            toDouble = std::numeric_limits<double>::infinity();
        }
        catch (std::exception &)
        {

            try
            {
                toFloat = std::stof(input);
                toDouble = static_cast<double>(toFloat);
            }
            catch (...)
            {
            }
        }
    }
}