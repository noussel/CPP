#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange &other){
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other){
    if(this == &other)
        return *this;
    archive = other.archive;
    return *this;
}

float BitcoinExchange::getRate(str &date){
    std::map<str, float>::iterator it;
    it = archive.lower_bound(date);//key
    if(archive.empty())
    {
        std::cerr << "Error : empty data base \n";
    }
    if (it == archive.end())
    {
        --it;
        return it->second;
    }
    if(it->first == date)
        return it->second;
    if(it == archive.begin()){
        std::cerr << "Error : no earlier date\n";
        return -1;
    }
    --it;
    return it->second;
}

void BitcoinExchange::calculateResult(){
    str date = line.substr(0, line.find('|') - 1);
    str valueStr = line.substr(line.find('|') + 2);

    float value = std::atof(valueStr.c_str());
    float rate = getRate(date);

    if(rate != -1)
        outLine << date << " => " << value << " = " << (rate * value);
}

void BitcoinExchange::displayLine(){
    std::cout << outLine.str() << std::endl;
    outLine.str("");
    outLine.clear();
}

bool BitcoinExchange::valideFormat()
{
    size_t pos = line.find('|');

    if (pos == std::string::npos || pos != 11 || line[pos - 1] != ' ' || line[pos + 1] != ' ')
    {
        std::cout << "Error: bad line format => " << line << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isNumber(str date){
    for(int i = 0; date[i]; i++){
        if(!isdigit(date[i]) && date[i] != '-')
            return false;
    }
    return true;
}

bool BitcoinExchange::valideDate()
{
    str date = line.substr(0, line.find('|') -1);

    if (date.length() != 10 || date[4] != '-' || date[7] != '-' || !isNumber(date))
    {
        std::cout << "Error: bad date Format => " << date << std::endl;
        return false;
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    // std::cout << "--------------> " << year << "\n";
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year > 2026 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cout << "Error: bad date numbers => " << date << std::endl;
        return false;
    }
    // outLine << date << " => ";
    return true;
}

bool BitcoinExchange::valideValue()
{
    std::string valueStr = line.substr(line.find('|') + 2);
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
    // outLine << value << " = ";
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

void BitcoinExchange::fillArchive(str DB){
    std::ifstream dataBase(DB.c_str());
    if(!dataBase){
        throw "Error : File can not be opened\n";
    }
    str date;
    // str line;
    float rate;
    getline(dataBase, line);
    while(std::getline(dataBase, line)){//yyy-mm-dd,rate
        size_t pos = line.find(",");
        if (pos == str::npos)
            continue;
        date = line.substr(0, pos);
        rate = std::atof(line.substr(pos + 1).c_str());
        archive[date] = rate;
    }
    line = "";
}

void BitcoinExchange::analyse(str input){
    std::ifstream userdata(input.c_str());
    if(!userdata)
        throw "Error : User file can not be opened\n";
    // str line;
    std::getline(userdata, line);

    while(std::getline(userdata, line)){
        if(!valideLine())//will out if not valide 
            continue;
        calculateResult();
        displayLine();
    }
}