#include "ScalarConverter.hpp"

int main(int ac, char *argv[])
{
    try{
        if(ac != 2)
            throw ERROR();      
        ScalarConverter::convert(argv[1]);

    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}