#include "ClapTrap.hpp"
#include "ScavTrap.hpp"



int main()
{
    ScavTrap scav1("Scavvy");
    ScavTrap scav2 = scav1; 
    ScavTrap scav3;
    scav3 = scav1; 

    scav1.attack("Target1");
    scav1.guardGate();

    scav2.attack("Target2");
    scav2.guardGate();

    scav3.attack("Target3");
    scav3.guardGate();

    return 0;
}