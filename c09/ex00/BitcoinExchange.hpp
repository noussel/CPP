#pragma once
#include <iostream>
#include <algorithm>
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
    return *this;
}

BitcoinExchange::fillMap(std::string DB){
    std::ifstream dataBase(DB.c_str());
    if(!dataBase){
        throw "file can't be opened\n";
    }
    std::string line;
    std::string date;
    double rate;
    getline(dataBase, line);
    while(std::getline(dataBase, line)){//yyy-mm-dd,rate
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            continue;
        date = line.substr(0, pos);
        rate = std::strtod(line.substr(pos + 1));
        archiffe[date] = rate;
    } 

}
