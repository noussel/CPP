#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
    private :
        Weapon &slah;
        std::string name;
    public :
        HumanA(std::string name, Weapon &slah);
        void attack();
};

#endif