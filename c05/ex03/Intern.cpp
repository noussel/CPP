#include "Intern.hpp"


Intern::Intern(){};

Intern::Intern(Intern &other){
    (void) other;
};

Intern &Intern::operator=(Intern &other){
    (void) other;
    return(*this);
}
Intern::~Intern(){}

int Intern::wichForm(std::string FormName){
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for(int i = 0; i < 3; i++){
        if(forms[i] == FormName)
            return i;
    }
    return -1;
}

AForm *Intern::makeForm(std::string formName, std::string target){
    AForm *f = NULL;
    switch (wichForm(formName))
    {
    case 0:
        f = new PresidentialPardonForm(target);
        break;
    case 1:
        f = new RobotomyRequestForm(target);
        break;
    case 2:
        f = new ShrubberyCreationForm(target);
        break;
    default:{
        std::cout << "invalid Form name ! \n";
        return NULL;
    }
    }
    std::cout << "Intern creates " << f->getName() << std::endl;
    return f;
}