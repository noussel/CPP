#include "RPN.hpp"

int main(int ac, char **av){
    try{
        if(ac != 2)
            throw std::runtime_error("invalide number of argements\n");
        RPN rpn;
        rpn.calculater(av[1]);        
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}