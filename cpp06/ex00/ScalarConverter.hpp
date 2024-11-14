#pragma once

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <stdexcept>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter() {};
        //ScalarConverter(const ScalarConverter &original) {};
        //ScalarConverter &operator=(const ScalarConverter &original) {return (*this);};
        ~ScalarConverter() {};

        static bool    isChar(std::string const &num);
        static bool    isInt(std::string const &num);
        static bool    isFloat(std::string const &num);
        static bool    isDouble(std::string const &num);

        static void    printChar(char num);
        static void    printInt(int num);
        static void    printFloat(float num);
        static void    printDouble(double num);

    public:
        static void convert(const std::string &num);

};