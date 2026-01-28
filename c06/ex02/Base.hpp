#pragma once
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>


class Base{
    public :
        virtual ~Base();
};


Base *generate(void);
void identify(Base* p);
void identify(Base& p);