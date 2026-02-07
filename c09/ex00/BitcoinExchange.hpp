#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>

class BitcoinExchange{

    private :
        std::map<std::string, float> archiffe;


    protected :
        typedef typename std::string str;
        str line;
        str outLine;

        bool valideLine(std::string line);//print mssg   présence de |  position correcte  pas une line vide  date & value valide  
        bool valideFormat(const std::string &line);
        bool valideDate(const std::string &line);
        bool valideValue(const std::string &line);
        float getRate(std::string &date);//récupérer le bon taux depuis la map & gérer le cas “date inexistante”
        void outLine(std::string line);//date => value = result


    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);
        ~BitcoinExchange();

        void fillMap(std::string DB);
        void analyse(std::string input);//lire valider calculer afficher 

};

bool BitcoinExchange::valideFormat(const std::string &line)
{
    size_t pos = line.find('|');

    if (pos == std::string::npos)
    {
        std::cout << "Error: bad format => " << line << std::endl;
        return false;
    }
    if (pos != 11)
    {
        std::cout << "Error: bad format => " << line << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::valideDate(const std::string &line)
{
    std::string date = line.substr(0, line.find('|'));

    if (date.length() != 11 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad date => " << date << std::endl;
        return false;
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cout << "Error: bad date => " << date << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::valideValue(const std::string &line)
{
    std::string valueStr = line.substr(line.find('|') + 2);//to skep space after "|" " 42"
    double value = std::atof(valueStr.c_str());

    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


bool BitcoinExchange::valideLine(){
    if(line.empty()){
        std::cout << "Error : empty line \n";
        return false;
    }
    if (!valideFormat(line))
        return false;
    if (!valideDate(line))
        return false;
    if (!valideValue(line))
        return false;
    return true;
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

void BitcoinExchange::fillMap(str DB){
    std::ifstream dataBase(DB.c_str());
    if(!dataBase){
        throw "file can't be opened\n";
    }
    str date;
    str line;
    float rate;
    getline(dataBase, line);
    while(std::getline(dataBase, line)){//yyy-mm-dd,rate
        size_t pos = line.find(",");
        if (pos == str::npos)
            continue;
        date = line.substr(0, pos);
        rate = std::atof(line.substr(pos + 1).c_str());
        archiffe[date] = rate;
    }
}

void BitcoinExchange::analyse(str input){
    std::ifstream userdata(input.c_str());
    if(!userdata)
        throw "User file can not be opened\n";
    str out;
    std::getline(userdata, line);
    while(std::getline(userdata, line)){
        if(!(valideLine()))//will out if not valide 
            continue;
        outLine();
    }
}