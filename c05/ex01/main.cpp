#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

    try {
        Bureaucrat bob("BOB", 150);
        Bureaucrat jim("JIM", 1);

        Form f("FORLMULAA", 100, 70);
        Form c("CONTRAT", 1 , 2);

        std::cout << f;
        std::cout << c << std::endl;

        std::cout << bob;
        std::cout << jim << std::endl;
        
        bob.signForm(f);
        jim.signForm(f);

        jim.signForm(c);
        bob.signForm(c);
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