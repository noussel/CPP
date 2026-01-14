#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class PresidentialPardonForm : public AForm{
    private :
        std::string target;
    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        virtual ~PresidentialPardonForm();
    protected :
        void executeAction(Bureaucrat const &executor) const;
    };



