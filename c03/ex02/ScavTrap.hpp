#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public :
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        void guardGate();//affiche in gate keeper mode   
        void attack(const std::string& target);
        ~ScavTrap();
};


#endif