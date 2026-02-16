#include "PmergeMe.hpp"

int main(int ac, char **av){
    (void) av;
    try{
        if (ac < 2)
            throw std::runtime_error("Empty list\n");
        PmergeMe pm;
        std::vector<int> vec;
        std::vector<int> deq;
        pm.parseInput(av);
        pm.FordJohnson(pm.vec);
        pm.FordJohnson(pm.deq);
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
    return 0;
}