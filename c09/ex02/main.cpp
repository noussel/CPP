// #include "PmergeMe.hpp"

// int main(int ac, char **av){
//     (void) av;
//     try{
//         if (ac < 2)
//             throw std::runtime_error("Empty list\n");
//         PmergeMe pm;

//         pm.parseInput(av);
//         pm.FordJohnson(pm.getDeq());
//         pm.FordJohnson(pm.getVect());
//         std::cout << pm << std::endl;
//     }
//     catch(std::exception &e){
//         std::cerr << e.what();
//     }
//     return 0;
// }

#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::runtime_error("Error: empty list\n");

        PmergeMe pm;
        pm.parseInput(av);

        // BEFORE
        std::cout << "Before: ";
        for (size_t i = 0; i < pm.getVect().size(); i++)
            std::cout << pm.getVect()[i] << " ";
        std::cout << std::endl;

        // -------- VECTOR --------
        std::clock_t startVec = std::clock();
        pm.FordJohnson(pm.getVect());
        std::clock_t endVec = std::clock();

        double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

        // -------- DEQUE --------
        std::clock_t startDeq = std::clock();
        pm.FordJohnson(pm.getDeq());
        std::clock_t endDeq = std::clock();

        double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

        // AFTER
        std::cout << "After:  ";
        for (size_t i = 0; i < pm.getVect().size(); i++)
            std::cout << pm.getVect()[i] << " ";
        std::cout << std::endl;

        // TIMING
        std::cout << "Time to process a range of "
                  << pm.getVect().size()
                  << " elements with std::vector : "
                  << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of "
                  << pm.getDeq().size()
                  << " elements with std::deque  : "
                  << timeDeq << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }

    return 0;
}
