#pragma once

#include <cstdlib>   // atoi, strtod
#include <climits>    // numeric_limits
#include <cmath>     // isnan, isinf (plus tard)
#include <cfloat>

#include <iostream>
#include <exception>

class ScalarConverter {
    private :
        ScalarConverter();
        ScalarConverter(ScalarConverter &other);
    public :
        ScalarConverter &operator=(ScalarConverter &other);
        static void convert(std::string arg);
        ~ScalarConverter();
};

class ERROR : public std::exception{
    const char *what() const throw();
};

enum TYPE{
    IS_CHAR,
    IS_INT,
    IS_FLOAT,
    IS_DOUBLE,
    IS_sPECIAL,
    IS_INVALID,
};