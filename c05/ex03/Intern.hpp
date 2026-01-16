#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
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
        AForm *ShrubberyCreation(std::string &target);
        AForm *PresidentialPardon(std::string &target);
        AForm *RobotomyRequest(std::string &target);
        ~Intern();
};

class InvalidFormName : public std::exception {
    const char *what() const throw();
};

