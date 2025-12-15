#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private : 
        Brain *ideas;
public :
        Cat();
        Cat (const Cat &other);
        const std::string getIdeas(int index)const ;
        void setIdeas(int index ,std::string str);
        Cat &operator=(const Cat &other);
        void makeSound()const;
        ~Cat();
};


#endif
