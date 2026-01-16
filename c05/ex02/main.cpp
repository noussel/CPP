#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

    try {
        Bureaucrat boss("BOSS", 1);
        Bureaucrat jim("JIM", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm Robot("home");
        PresidentialPardonForm presedent("home");
        
        std::cout << boss;
        std::cout << jim << std::endl;
        
        boss.signForm(shrub);
        boss.signForm(Robot);
        boss.signForm(presedent);

        jim.signForm(shrub);
        jim.signForm(Robot);
        jim.signForm(presedent);

        boss.executeForm(shrub);
        boss.executeForm(Robot);
        boss.executeForm(presedent);

        ShrubberyCreationForm test("test");//test non signe
        jim.executeForm(test);

    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}
