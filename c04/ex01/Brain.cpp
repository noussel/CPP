#include "Brain.hpp"



Brain::Brain(){
    std::cout << "Brain Default constructor\n";
}

Brain::Brain(const Brain &other){
    *this = other;
    std::cout << "Brain Copy constructor\n";
}

Brain &Brain::operator=(const Brain &other){
    if(this != &other)
        for(int i=0; i < 100 ;i++){
            this->ideas[i] = other.ideas[i];
        }
    return *this;
    
}

void Brain::setBrainIdeas(int index, std::string str){
    if(index >= 0 && index < 100)
        this->ideas[index] = str;
}

std::string Brain::getBrainIdeas(int index){
    if(index >= 0 && index < 100)
        return ideas[index];
    return " ";
}

Brain::~Brain(){
    std::cout << "Brain Destroyed\n";
}