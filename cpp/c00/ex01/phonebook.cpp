#include <iostream>
#include "phonebook.hpp"

void phonebook::add_contact()
{
    int index = total % 8; // pour écraser le plus ancien si plein
    contacts[index].setinfo();
    if(total < 8)
        total++;
}

void phonebook::displayShortAll(int index) const
{
    if (total == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for(int i = 0; i < total; i++)
        contacts[i].displayshort(i);
}

void phonebook::display_full_contact(int index)const//to check totale
{
    if(total == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    //if index < 0 || >= total
    contacts[index].displayfull();
}


