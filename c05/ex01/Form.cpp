
#include "Form.hpp"

Form::Form() : name("default") ,Signed(false), signGrade(150), execGrade(150){

}

Form::Form(std::string const &name, int sgrade, int egrade) : name(name), signGrade(sgrade), execGrade(egrade){
    if(sgrade > 150 || egrade > 150)
        throw GradeTooLowException();
    if(sgrade < 1 || egrade < 1)
        throw GradeTooHighException();
    Signed = false;
}

Form &Form::operator=(Form &other){
    if(&other == this)
        return *this;
    this->Signed = other.getSignGrade();
    return *this;
}

void Form::beSigned(Bureaucrat &b){
    if(b.getGrade() > signGrade)
        throw GradeTooLowException();
    Signed = true;
}

bool Form::getSign() const{
    return(Signed);
}

int Form::getExecGrade() const{
    return(execGrade);
}

int Form::getSignGrade() const{
    return(signGrade);
}

std::string const &Form::getName()const{
    return(name);
}

const char *Form::GradeTooHighException::what()const throw(){
    return("Form throw => Grade too high\n");
}
const char *Form::GradeTooLowException::what()const throw(){
    return("Form throw => Grade too Low\n");
}

Form::Form(Form const &other) 
        : name(other.name), 
        signGrade(other.getSignGrade()), 
        execGrade(other.getExecGrade())
        {
    Signed = other.getSign();
}

Form::~Form(){
    
}

std::ostream &operator<<(std::ostream &out, Form &f){
    out << "Form name: " << f.getName() << ", Signed = " 
        << f.getSign() << ", sign grade = " << f.getSignGrade() 
        << ", execution grade = " << f.getExecGrade() << std::endl;
    return(out);
}