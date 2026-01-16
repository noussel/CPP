#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm *f1 = NULL;
    AForm *f2 = NULL;
    AForm *f3 = NULL;
    AForm *f4 = NULL;

    try
    {
        f1 = someRandomIntern.makeForm("shrubbery creation", "semence");
        f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        f3 = someRandomIntern.makeForm("presidential pardon", "Alice");

            boss.signForm(*f1);
            boss.executeForm(*f1);

            boss.signForm(*f2);
            boss.executeForm(*f2);

            boss.signForm(*f3);
            boss.executeForm(*f3);

        f4 = someRandomIntern.makeForm("random form", "nobody");
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
