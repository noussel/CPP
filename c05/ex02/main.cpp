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

        jim.signForm(shrub);//grade too low
        jim.signForm(Robot);//grade too low
        jim.signForm(presedent);//grade too low

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

/*
int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Bureaucrat jim("Jim", 140);

        Form contract("Contract", 100, 50);
        Form secret("Secret", 10, 1);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;

        std::cout << contract << std::endl;
        std::cout << secret << std::endl;

        // Jim essaye de signer (échec)
        jim.signForm(contract);

        // Bob signe (succès)
        bob.signForm(contract);

        // Bob essaye de signer un form trop haut
        bob.signForm(secret);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
*/