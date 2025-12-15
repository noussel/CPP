#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal{
    private :
        Brain *ideas;
    public :
        Dog();
        Dog (const Dog &other);
        const std::string getIdeas(int index)const;
        void setIdeas(int index, std::string str);
        Dog &operator=(const Dog &other);
        void makeSound() const ;
        ~Dog();
};


#endif