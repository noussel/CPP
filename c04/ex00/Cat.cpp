#include "Cat.hpp"


Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default constructor\n";
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &other){
    if(this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

const std::string &Cat::getType()const {
    return this->type;
}

void Cat::makeSound()const {
    std::cout << "Cat sound \n";
}

Cat::~Cat(){
    std::cout << "Cat destroyed\n";
}