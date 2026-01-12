#pragma once

#include <iostream>
#include <exception>





class Form ;


class Bureaucrat{
    private :
        std::string const name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(std::string, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        int getGrade() const;
        std::string const &getName() const;
        void incrGrade();//--
        void decGrade();//++
        class GradeTooHighException : public std::exception{
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char *what() const throw();
        };
        void signForm(Form &f);
        ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &out,const Bureaucrat &other);
