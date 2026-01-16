#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


class Form {
    private :
        std::string const name;
        bool Signed;
        int const signGrade;
        const int execGrade;
    public :
        Form();
        Form(std::string const &name, int sgrade, int egrade);//signed = 0 
        Form(Form const &other);
        Form &operator=(Form &other);
        std::string const &getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &b);
        class GradeTooHighException : public std::exception{
            const char *what()const throw();//noexcept
        };
        class GradeTooLowException : public std::exception{
            const char *what()const throw();//noexcept
        };
        ~Form();
};

std::ostream &operator<<(std::ostream &out, Form &toPrint);
