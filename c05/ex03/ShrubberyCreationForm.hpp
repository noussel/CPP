#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
    private :
        std::string target;
    public :
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        virtual ~ShrubberyCreationForm();
    protected :
        void executeAction(Bureaucrat const &executor) const;
    };
    
class FileException : public std::exception{
    const char *what() const throw();
};

