#include <iostream>
#include "phonebook.hpp"

void phonebook::add_contact()
{
    int index = counter % 8;
    std::string commande, FirstName, LastName, NickName, DarkestSecret, PhoneNumber;
    std::cout << "First Name: ";
    std::getline(std::cin, FirstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, LastName);
    std::cout << "Nick Name: ";
    std::getline(std::cin, NickName);
    std::cout << "Phone Number: ";
    std::getline(std::cin, PhoneNumber);
    while(isNumber(PhoneNumber) == 0)
    {
        std::cout << "invalide number.\n";
        std::cout << "Phone Number: ";
        std::getline(std::cin, PhoneNumber);
    }
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, DarkestSecret);
    if(FirstName.empty() || LastName.empty() || NickName.empty() || DarkestSecret.empty() || PhoneNumber.empty())
    {
        std::cout << "Contact can not be created (empty field)\n";
        return;
    }
    contacts[index].setinfo(FirstName, LastName, NickName, DarkestSecret, PhoneNumber);
    
    std::cout << "index == " << index << "\n";
    counter++;
    total = (counter < 8)? counter : 8;
}

void phonebook::displayShortAll()
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for(int i = 0; i < total; i++)
        contacts[i].displayshort(i);
}

void phonebook::display_full_contact(int index)//to check totale
{
    if(total == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    if(index >= total || index < 0)
    {
        std::cout << "Invalide index.11 " << "total = " << total << " index = " << index << std::endl;
        return;
    }
    contacts[index].displayfull();
}

int phonebook::get_total()
{
    return(total);
}
