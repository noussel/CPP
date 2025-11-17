#include "contact.hpp"
#include <iostream>
#include <iomanip>


int isNumber(std::string s)
{
    for(int i = 0; s[i]; i++)
    {
        if(!std::isdigit(s[i]))
            return(0);
    }
    return(1);
}

void contact::setinfo(std::string FirstName,std::string LastName,std::string NickName,std::string DarkestSecret,std::string PhoneNumber)
{
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->NickName = NickName ;
    this->PhoneNumber = PhoneNumber;
    this->DarkestSecret = DarkestSecret;
}

void printcolumn(const std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << str << "|";
}

void contact::displayshort(int index)
{
    // std::cout << "---------------------------------------------" << std::endl;
    // std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
    // std::cout << "---------------------------------------------" << std::endl;

    std::cout << "|" << std::setw(10) << index << "|";
    printcolumn(FirstName);
    printcolumn(LastName);
    printcolumn(NickName);
    std::cout << std::endl;
}

void contact::displayfull()
{
    std::cout << "First name : " << FirstName << std::endl;
    std::cout << "Last name : " << LastName << std::endl;
    std::cout << "Nick name : " << NickName << std::endl;
    std::cout << "Phone number : " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret : " << DarkestSecret << std::endl;
}
