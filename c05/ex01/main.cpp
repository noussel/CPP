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


