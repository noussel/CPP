#include "ClapTrap.hpp"

int main(){
    ClapTrap a("robot");
    ClapTrap b("enmy");

    a.attack("enmy");
    b.takeDamage(10);

    a.attack("enmy");
    a.beRepaired(5);

    b.beRepaired(5);
    b.attack("robot");
}