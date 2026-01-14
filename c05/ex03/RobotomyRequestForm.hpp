#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class RobotomyRequestForm : public AForm{
    private :
        std::string target;
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        virtual ~RobotomyRequestForm();
    protected :
        void executeAction(Bureaucrat const &executor) const;
    };


