#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <map>
#include <sstream>


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
        void calculateResult();
        void displayLine();//date => value = result

    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);
        ~BitcoinExchange();

        void fillMap(std::string DB);
        void analyse(std::string input);//lire valider calculer afficher 

};
