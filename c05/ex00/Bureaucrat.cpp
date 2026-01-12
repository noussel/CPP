#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade(150) {
}

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n){
    if(g < 1)
        throw GradeTooHighException();
    if(g > 150)
        throw GradeTooLowException();
    grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name){
    grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copiedfrom){
    if(&copiedfrom == this)
        return(*this);
    this->grade = copiedfrom.grade;
    return(*this);
}

void Bureaucrat::incrGrade(){
        if(grade <= 1)
            throw GradeTooHighException();
        grade--;
}

void Bureaucrat::decGrade(){
        if(grade >= 150)
            throw GradeTooLowException();
        grade++;
}

std::ostream &operator<<(std::ostream &out,const Bureaucrat &other){
    out << other.getName() << " , bureaucrat grade " << other.getGrade() << "\n";
    return(out);
}


int Bureaucrat::getGrade() const{
    return(grade);
}
std::string const &Bureaucrat::getName() const {
    return(name);
}

char const* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high\n";
}

char const* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low\n";
}

Bureaucrat::~Bureaucrat(){

}