#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
    hitPoints = 100;
    energyPoints  = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor \n";
}
void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode !\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    if(this != &other)
    {
    this->Name = other.Name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "ScavTrap Copy assignment \n";
    }
   
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
    // *this = other;
    std::cout << "ScavTrap copy constructor called \n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    Name = name;
    hitPoints = 100;
    energyPoints  = 50;
    attackDamage = 20;
}

void ScavTrap::attack(const std::string& target) {
    if(hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << Name << " attack " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << Name << " cannot attack !\n";
}

ScavTrap::~ScavTrap(){
    std::cout << Name << " ScavTrap destroyed\n";
}
