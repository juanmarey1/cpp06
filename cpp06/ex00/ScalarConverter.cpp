#include "ScalarConverter.hpp"

bool    ScalarConverter::isChar(std::string const &num)
{
    if (num.length() == 1) {
        if (num[0] < 32 || num[0] > 126) {
            return (false);
        }
        return (true);
    }
    else if (num.length() == 3) {
        if (num[0] == '\'' && num[2] == '\'') {
            if (num[1] < 32 || num[1] > 126) {
                return (false);
            }
            return (true);
        }
        return (false);
    }
    return (false);
}

bool    ScalarConverter::isInt(std::string const &num)
{
    char    *ptr;
    long    number;
    try 
    {
        number = std::strtol(num.c_str(), &ptr, 10);
        if (*ptr != '\0')
            return (false);

        if (number > INT_MAX || number < INT_MIN)
            return (false);
        return (true);

    }   
    catch (...)
    {
        return (false);
    }
}

bool    ScalarConverter::isFloat(std::string const &num)
{
    char    *ptr;
    std::string num1;
    num1 = num;
    try
    {
        if (num == "-inff" || num == "+inff" || num == "nanf")
            return (true);
        if (num == "-inf" || num == "+inf")
            return (false);

        if (num1[num1.size() - 1] != 'f')
            return (false);
        num1 = num1.erase(num1.size() - 1);
        std::cout << num1 << std::endl;
        double   number = std::strtod(num1.c_str(), &ptr);
        (void)number;
        if (*ptr != '\0')
            return (false);
        return (true);

    }
    catch (...)
    {
        return (false);
    }
    
}

bool    ScalarConverter::isDouble(std::string const &num)
{
    char    *ptr;
    try
    {
        if (num == "-inf" || num == "+inf" || num == "nan")
            return (true);

        double  number = std::strtod(num.c_str(), &ptr);
        (void)number;
        if (*ptr != '\0')
            return (false);
        return (true);

    }
    catch (...)
    {
        return (false);
    }
    
}

void    ScalarConverter::printChar(char num)
{
    std::cout << "char: '" << num << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void    ScalarConverter::printInt(int num)
{
    if (num > 32 && num < 127)
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void    ScalarConverter::printFloat(float num)
{
    if (num == std::isnan(num) || num == std::isinf(num))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << num << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
        return ;
    }

    if (num > 32 && num < 127)
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (num > static_cast<float>(INT_MAX) || num < static_cast<float>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;

    if (num - static_cast<int>(num) != 0)
    {
        std::cout << "float: " << num << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
    else
    {
        std::cout << "float: " << num << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
    }
}

void    ScalarConverter::printDouble(double num)
{
    if (num == std::isnan(num) || num == std::isinf(num))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << num << "f" << std::endl;
        std::cout << "double: " << num << std::endl;
        return ;
    }

    if (num > 32 && num < 127)
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (num > static_cast<double>(INT_MAX) || num < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    if (num - static_cast<int>(num) != 0)
    {
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << num << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
        std::cout << "double: " << num << ".0" << std::endl;
    }
}

void ScalarConverter::convert(std::string const &num)
{
    try 
    {
        if (isChar(num))
        {
            char    num_cpy;
            if (num.length() == 3)
                num_cpy = num[1];
            else
                num_cpy = num[0];
            printChar(num_cpy);
        }
        else if (isInt(num))
        {
            int num_cpy = std::atoi(num.c_str());
            printInt(num_cpy);
        }
        else if (isFloat(num))
        {
            char    *ptr1;
            std::string num1 = num;

            num1 = num1.erase(num1.size() - 1);
            float   num_cpy = std::strtof(num1.c_str(), &ptr1);
            printFloat(num_cpy);
        }
        else if (isDouble(num))
        {
            char    *ptr2;
            double  num_cpy = std::strtod(num.c_str(), &ptr2);
            printDouble(num_cpy);
        }
        else
        {
            throw std::runtime_error("invalid format");
        }
    }
    catch (const std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}