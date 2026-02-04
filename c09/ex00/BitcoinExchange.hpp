#pragma once
#include <iostream>
#include <algoritms>
#include <fstream>
#include <utility>

class BitcoinExchange{
    private :
        std::map<std::string , float> archiffe;
    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);
        void fillMap(std::string DB);
        void valideLigne(std::string ligne);
        float getRate(std::map<std::string, float> archiffe);
        void analyse(std::string input);//lire valider calculer afficher 
        ~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange &other){
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other){
    if(this == &other)
        return *this;
    archiffe = other.archiffe;
}

BitcoinExchange::fillMap(std::string DB){
    std::ifstream dataBase(DB.c_str);
    if(!dataBase){
        throw "file can't be opened\n";
    }
    std::string line;
    getline(dataBase, line);
    while(std::getline(dataBase, line)){
        size_t pos = line.find(",");

        archiffe.insert(std::pair(substr(pos), rate));
    }

}
