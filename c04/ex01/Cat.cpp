#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default constructor\n";
    ideas = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy constructor\n";
    this->ideas = new Brain(*other.ideas);
}

Cat &Cat::operator=(const Cat &other){
    if(this == &other)
        return *this;
    *ideas = *other.ideas;
    return *this;
}

void Cat::setIdeas(int index, std::string str){
        this->ideas->setBrainIdeas(index, str);
}

const std::string Cat::getIdeas(int index)const {
    return this->ideas->getBrainIdeas(index);
}

void Cat::makeSound()const {
    std::cout << "Cat sound \n";
}

Cat::~Cat(){
    delete ideas;
    std::cout << "Cat destroyed\n";
}