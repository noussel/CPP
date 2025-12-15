#include "Dog.hpp"
#include "Brain.hpp"



Dog::Dog(){
    this->type = "Dog";
    this->ideas = new Brain();
    std::cout << "Dog Default constructor \n";
}

Dog::Dog(const Dog &other) : Animal(other){
    this->ideas = new Brain(*other.ideas);
    std::cout << "Dog copy constructor\n";

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
    std::cout << "Dog destroyed\n";
    delete ideas;
}