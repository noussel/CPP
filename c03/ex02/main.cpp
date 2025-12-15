#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Fraggy");
    FragTrap frag2 = frag1; 
    FragTrap frag3;
    frag3 = frag1; 

    frag1.attack("Target1");
    frag1.highFivesGuys();

    frag2.attack("Target2");
    frag2.highFivesGuys();

    frag3.attack("Target3");
    frag3.highFivesGuys();

    return 0;
}
