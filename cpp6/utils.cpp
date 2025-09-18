#include "ScalarConverter.hpp"

bool my_isprint(char ch)
{
    return std::isprint(static_cast<unsigned char>(ch));
}

bool IsPseudo(const std::string &input)
{
    for (size_t i = 0; i < pseudoLiterals.size(); i++)
    {
        if (input == pseudoLiterals[i])
        {           
            std::cout << "char: impossible\n"
                      << "int: impossible\n";

            if (input == "nanf" || input == "nan")
                std::cout << "float: nanf\n"
                          << "double: nan\n";
            else if (input == "+inff" || input == "+inf")
                std::cout << "float: +inff\n"
                          << "double: +inf\n";
            else if (input == "-inff" || input == "-inf")
                std::cout << "float: -inff\n"
                          << "double: -inf\n";

            return true;
        }
    }
    return false;
}


