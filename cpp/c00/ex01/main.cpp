#include "phonebook.hpp"
#include <cctype>
#include <iostream>

int notValide(std::string commande)
{
    if(commande.compare("ADD") && commande.compare("SEARCH") && commande.compare("EXIT"))
        return 1;
    return 0;
}

int isNumber(std::string s)
{
    for(int i = 0; s[i]; i++)
    {
        if(!std::isdigit(s[i]))
            return(0);
    }
    return(1);
}

int main()
{
    std::string commande;
    phonebook pb;
    pb.total = 0;
    std::cout << "___PHONEBOOK___" << std::endl;
    while(1)
    {
        std::cout << "PhoneBook : ";
        std::getline(std::cin, commande);
        if(notValide(commande))
        {
            std::cout << "Please insert a valide commande !\n";
        }
        if(commande == "EXIT")
            exit(0);
        if(commande == "ADD")
            pb.add_contact();
        if(commande == "SEARCH")
        {
            pb.displayShortAll();
            std::cout << "Insert the index : ";
            getline(std::cin, commande);
            if(!isNumber(commande))
                std::cout << "Invalide number ! \n";
            else if (std::stoi(commande) > 9)
                std::cout << "Number is out of bounds ! \n";
            else 
                pb.display_full_contact(std::stoi(commande));
        }
    }
}