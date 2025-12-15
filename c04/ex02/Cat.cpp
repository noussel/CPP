#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(){
    this->type = "Cat";
    ideas = new Brain();
    std::cout << "Cat Default constructor\n";
}

Cat::Cat(const Cat &other) : Animal(other){
        this->ideas = new Brain(*other.ideas);

    std::cout << "Cat copy constructor\n";
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
    std::cout << "Cat destroyed\n";
    delete ideas;
}