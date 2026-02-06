#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>

class BitcoinExchange{
    private :
        std::map<std::string , float> archiffe;
    protected :
        std::string line;
        bool valideLine(std::string line);//print mssg   présence de |  position correcte  pas une line vide  date & value valide  
        float getRate(std::string &date);//récupérer le bon taux depuis la map & gérer le cas “date inexistante”
        void outLine(std::string line);//date => value = result
    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);
        typdef typename std::string str;
        void fillMap(std::string DB);
        void analyse(std::string input);//lire valider calculer afficher 
        ~BitcoinExchange();
};

bool BitcoinExchange::valideLine(std:string line){
    if(line.empty())
        std::cout << "Error : empty line \n";
    else if(line )
}

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
    std::string date;
    float rate;
    getline(dataBase, line);
    while(std::getline(dataBase, line)){//yyy-mm-dd,rate
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            continue;
        date = line.substr(0, pos);
        rate = std::atof(line.substr(pos + 1).c_str);
        archiffe[date] = rate;
    }
}

void BitcoinExchange::analyse(std::string input){
    std::ifstream userdata(input.c_str());
    if(!userdata)
        throw "User file can not be opened\n";
    std::string out;
    std::getline(userdata, line);
    while(std::getline(userdata, line)){
        if(!(valideLine(line)))//will out
            continue;
        outLine(line);
    }
}