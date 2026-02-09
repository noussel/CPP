#include "RPN.hpp"

int main(int ac, char **av){
    try{
        if(ac != 2)
            throw run_time_error("invalide input\n");
        RPN rpn;
        rpn.calculater(av[1]);        
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}