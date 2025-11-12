#include <iostream>
#include "contact.hpp"

class phonebook
{
    private:
        contact contacts[9];
    public:
        
        int total;
        void add_contact();
        void displayShortAll(int index)const;//un seul contact en bref dans un tableau 
        void display_full_contact(int index)const;//les detail d'un contact 
};