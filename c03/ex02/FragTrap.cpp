#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints  = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor \n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called \n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints  = 100;
    attackDamage = 30;
    std::cout << "FragTrap Copy constructor name \n";
}

FragTrap &FragTrap::operator=(const FragTrap &other){
    if(this == &other)
        return *this;
    this->Name = other.Name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

void FragTrap::highFivesGuys(){
    std::cout << "High-fives please !\n";
}

void FragTrap::attack(const std::string& target) {
    if(hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << Name << " attack " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
        return;
    }
    std::cout << "FragTrap " << Name << " cannot attack !\n";
}

FragTrap::~FragTrap(){
    std::cout << Name << " FragTrap destroyed\n";
}
