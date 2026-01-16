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

const char *InvalidFormName::what() const throw(){
        return "invalid Form name ! \n";
}

AForm *Intern::PresidentialPardon(std::string &target){
    return new PresidentialPardonForm(target);
}

AForm *Intern::ShrubberyCreation(std::string &target){
    return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyRequest(std::string &target){
    return new RobotomyRequestForm(target);
}

int Intern::wichForm(std::string FormName){
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for(int i = 0; i < 3; i++){
        if(forms[i] == FormName)
            return i;
    }
    throw InvalidFormName();
}

AForm *Intern::makeForm(std::string formName, std::string target){
    AForm *(Intern::*fun_ptr[3])(std::string&) = {
        &Intern::PresidentialPardon,
        &Intern::RobotomyRequest,
        &Intern::ShrubberyCreation,
    };
    return (this->*fun_ptr[wichForm(formName)])(target);
}
