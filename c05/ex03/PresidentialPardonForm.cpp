#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), target(target){

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 145, 137), target(other.target){
        
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
    if(this != &other)
        this->target = other.target;
    return *this;
}

void PresidentialPardonForm::executeAction(Bureaucrat const &executor) const
{
    (void) executor;
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}


PresidentialPardonForm::~PresidentialPardonForm(){
    
}