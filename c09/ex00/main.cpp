#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    try {
        if(ac != 2)
            throw "INVALIDE IMPUT\n";
        BitcoinExchange btc;
        btc.fillMap("data.csv");
        btc.analyse(av[1]);
    }
    catch(char const *ErrorType){
        std::cerr << ErrorType;
    }    
}