#include "contact.hpp"
#include <iostream>
#include <iomanip>

void contact::setinfo()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter Nick Name: ";
    std::getline(std::cin, nick_name);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, DarkestSecret);
}

void printcolumn(const std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << str << "|";
}

void contact::displayshort(int index) const
{
    // std::cout << "---------------------------------------------" << std::endl;
    // std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
    // std::cout << "---------------------------------------------" << std::endl;

    std::cout << "|" << std::setw(10) << index << "|";
    printcolumn(first_name);
    printcolumn(last_name);
    printcolumn(nick_name);
    std::cout << std::endl;
}

void contact::displayfull()const
{
    std::cout << "first name : " << first_name << std::endl;
    std::cout << "last name : " << last_name << std::endl;
    std::cout << "nick name : " << nick_name << std::endl;
    std::cout << "Darkest Secret : " << DarkestSecret << std::endl;
}
