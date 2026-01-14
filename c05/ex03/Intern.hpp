#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    private :
        int wichForm(std::string FormName);
    public :
        Intern();
        Intern(Intern &other);
        Intern &operator=(Intern &other);
        AForm *makeForm(std::string formName, std::string target);
        ~Intern();
};
