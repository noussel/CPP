#include "Bureaucrat.hpp"

int main(){
    
    try{
        Bureaucrat b("othman", -1);
        b.incrGrade();
        std::cout << b;
        b.incrGrade();
        std::cout << b;
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }

    
    try{
        Bureaucrat b("othman", 2);
        Bureaucrat c("mohmad", 149);
        b = c;
        b.decGrade();
        std::cout << c;
        std::cout << b;
        b.decGrade();
        std::cout << b;
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}

