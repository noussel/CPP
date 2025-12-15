#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private :
        std::string name;
    public :

        Zombie();
        std::string getName();
        void announce(void);
        void setName(std::string);
        ~Zombie();
        
};
void randomChump(std::string name);
Zombie *newZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif