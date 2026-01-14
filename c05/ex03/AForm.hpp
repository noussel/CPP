#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"




// class Bureaucrat ;

class AForm {
    private :
        std::string const name;
        bool Signed;
        int const signGrade;
        const int execGrade;
    protected :
        void executeCheck(Bureaucrat const &executor) const ;
        virtual void executeAction(Bureaucrat const &executor) const = 0;
    public :
        AForm(std::string const &name, int sgrade, int egrade);
        AForm(AForm const &other);
        AForm &operator=(AForm &other);
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
        class FormNotSignedException : public std::exception{
            const char *what()const throw();//noexcept
        };
        void execute(Bureaucrat const &executor) const;
        virtual ~AForm();//virtual
};


