#include "phonebook.hpp"
#include "contact.hpp"
#include <cctype>
#include <iostream>



int notValide(std::string commande)
{
    if(commande.compare("ADD") && commande.compare("SEARCH") && commande.compare("EXIT"))
        return 1;
    return 0;
}



int main()
{
    std::string commande;
    phonebook pb;
    // pb.total = 0;
    std::cout << "___PHONEBOOK___" << std::endl;
    while(1)
    {
        std::cout << "PhoneBook : ";
        if(!std::getline(std::cin, commande))
            break;
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
            if (pb.get_total() == 0)
            {
                std::cout << "No contacts to display." << std::endl;
                continue;
            }
            pb.displayShortAll();
            std::cout << "Insert the index : ";
            getline(std::cin, commande);
            if(commande.empty())
            {
                std::cout << "Invalid index." << std::endl;
                continue;
            }
            else if(!isNumber(commande))
                std::cout << "Invalide number ! \n";
            else 
                pb.display_full_contact(std::stoi(commande));
        }
    }
}