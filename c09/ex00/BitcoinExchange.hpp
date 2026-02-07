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
        std::ostringstream outLine;//date => value = result

        bool valideLine();//print mssg   présence de |  position correcte  pas une line vide  date & value valide  
        bool valideFormat();
        bool valideDate();
        bool valideValue();
        float getRate(std::string &date);//récupérer le bon taux depuis la map & gérer le cas “date inexistante”
        void displayLine();//date => value = result

    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);
        ~BitcoinExchange();

        void fillMap(std::string DB);
        void analyse(std::string input);//lire valider calculer afficher 

};

float BitcoinExchange::getRate(str &date){
    std::map<str, float>::iterator it;
    it = archiffe.lower_bound(date);//key
    
    if(it == archiffe.begin()){
        std::cerr << "Error : no earlier date\n";
        return -1;
    }
    if(it->first == date)
        return it->second;
    --it;//if it == end or it between to dates we took the earlier (avant)
    return it->second;
}

float BitcoinExchange::calculateResult(){
    str date = line.substr(0, line.find('|') - 1);/// ??
    str valueStr = line.substr(linefind('|') + 2);

    float value = std::atoi(valueStr.c_str());
    float rate = getRate(date);

    if(rate != -1)
        float result = value * rate;
    outLine << result;
}

void BitcoinExchange::displayLine(){

    std::cout << outLine << std::endl;
}

bool BitcoinExchange::valideFormat()
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

bool BitcoinExchange::valideDate()
{
    std::string date = line.substr(0, line.find('|'));//find return size_t

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
    outLine << date << "=> ";
    return true;
}

bool BitcoinExchange::valideValue()
{
    std::string valueStr = line.substr(line.find('|') + 2);//to skep space after "|" " 42"
    float value = std::atof(valueStr.c_str());

    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large number." << std::endl;
        return false;
    }
    outLine << value << " = ";
    return true;
}

bool BitcoinExchange::valideLine(){
    if(line.empty()){
        std::cout << "Error : empty line \n";
        return false;
    }
    if (!valideFormat())
        return false;
    if (!valideDate())
        return false;
    if (!valideValue())
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

    std::getline(userdata, line);

    while(std::getline(userdata, line)){
        if(!(valideLine()))//will out if not valide 
            continue;
        displayLine();
    }
}