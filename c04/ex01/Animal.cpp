#include "Animal.hpp"



Animal::Animal(){
    this->type = "Animal";
    std::cout << "Animal Default constructor\n";
}

const std::string &Animal::getType()const{
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "cats don’t bark\n";
}

Animal::~Animal(){
    std::cout << "Animal Destroyed\n";
}

