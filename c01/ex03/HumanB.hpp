#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
    private :
        std::string name;
        Weapon *slah;
    public :
        HumanB(std::string name);
        void setWeapon(Weapon &slah);
        void attack();//affiche <name> attacks with their <weapon type>
};

#endif