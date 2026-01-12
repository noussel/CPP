#pragma once
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time


class Base{
    public :
        virtual ~Base();//reasons
};


Base *generate(void);
void identify(Base* p);
void identify(Base& p);


