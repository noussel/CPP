#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137), target(target){

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 145, 137), target(other.target){
        
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
    if(this != &other)
        this->target = other.target;
    return *this;
}

void RobotomyRequestForm::executeAction(Bureaucrat const &executor) const
{
    (void) executor;

    std::cout << "noiiiiiiiiiiiiiiisy sound..." << std::endl;

    std::srand(std::time(NULL));
    if(std::rand() % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << std::endl;
    }
}


RobotomyRequestForm::~RobotomyRequestForm(){
    
}