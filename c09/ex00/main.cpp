#include "BitcoinExchange.hpp"

int main(int ac, char av[][]){
    try {
        if(ac != 1)
            throw "INVALIDE IMPUT\n";
        BitcoinExchange btc;
        btc.fillMap("dataBase");
        btc.analyse(av[1][0]);
    }
    catch(str Error){
        std::cerr << Error;
    }    
}