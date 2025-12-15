#include "Dog.hpp"
#include "Brain.hpp"



Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default constructor \n";
    this->ideas = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy constructor\n";
    this->ideas = new Brain(*other.ideas);

}

Dog &Dog::operator=(const Dog &other){
    if(this == &other)
        return *this;
    *ideas = *other.ideas;
    return *this;
}

void Dog::setIdeas(int index, std::string str){
    ideas->setBrainIdeas(index, str);
}

const std::string Dog::getIdeas(int index) const{
    return ideas->getBrainIdeas(index);
}

void Dog::makeSound() const{
    std::cout << "Dog sound \n";
}

Dog::~Dog(){
    delete ideas;
    std::cout << "Dog destroyed\n";
}