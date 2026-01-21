
#include "AForm.hpp"

AForm::AForm(std::string const &name, int sgrade, int egrade) : name(name), signGrade(sgrade), execGrade(egrade){
    if(sgrade > 150 || egrade > 150)
        throw GradeTooLowException();
    if(sgrade < 1 || egrade < 1)
        throw GradeTooHighException();
    Signed = false;
}

AForm &AForm::operator=(AForm &other) {
    if(&other == this)
        return *this;
    this->Signed = other.getSignGrade();
    return *this;
}

std::ostream &operator<<(std::ostream &out, AForm &toPrint);

void AForm::execute(Bureaucrat const &executor) const {
    if (!this->Signed)
        throw FormNotSignedException();
    else if(executor.getGrade() > this->execGrade)
        throw GradeTooLowException();
    else
        this->executeAction(executor);
}

void AForm::beSigned(Bureaucrat &b){
    if(b.getGrade() > signGrade)
        throw GradeTooLowException();
    Signed = true;
}

bool AForm::getSign() const{
    return(Signed);
}

int AForm::getExecGrade() const{
    return(execGrade);
}

int AForm::getSignGrade() const{
    return(signGrade);
}

std::string const &AForm::getName()const{
    return(name);
}

const char *AForm::GradeTooHighException::what()const throw(){
    return(" => Grade too high\n");
}
const char *AForm::GradeTooLowException::what()const throw(){
    return(" => Grade too Low\n");
}

const char *AForm::FormNotSignedException::what() const throw(){
    return(" => Non signed Form\n");
}
AForm::AForm(AForm const &other) : name(other.name), signGrade(other.getSignGrade()), execGrade(other.getExecGrade()){
    Signed = other.getSign();
}

AForm::~AForm(){

}

std::ostream &operator<<(std::ostream &out, AForm &f){
    out << "AForm name: " << f.getName() << ", is Signed= " 
        << f.getSign() << ", sign grade= " << f.getSignGrade() 
        << ", execution grade= " << f.getExecGrade() << std::endl;
    return(out);
}