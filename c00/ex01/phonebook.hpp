#include <iostream>
#include "contact.hpp"

class phonebook
{
    private:
        contact contacts[8];
        int total = 0;
        int counter = 0;
    public:
        int get_total();
        void add_contact();
        void displayShortAll();//all contacts in bref
        void display_full_contact(int index);//les detail d'un contact 
};