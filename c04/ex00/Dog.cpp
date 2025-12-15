#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default constructor \n";
}

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &other){
    if(this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

const std::string &Dog::getType() const{
    return this->type;
}

void Dog::makeSound() const{
    std::cout << "Dog sound \n";
}

Dog::~Dog(){
    std::cout << "Dog destroyed\n";
}