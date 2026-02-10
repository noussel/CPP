#pragma once
#include <iostream>
#include <vecter>

template <typename T>
class  PmergeMe{
    private :
        T container;
    public :
        PmergeMe();
        PmergeMe(PmergeMe &other);
        PmergeMe &operator=(PmergeMe &other);
        void fill<T>();//check for duplication (usint std::set)& fill out the container 
        void FordJohnson<T>();//sorting algorithme -> create paires -> put max and min -> sort max values -> put min using binary search
        ~PmergeMe();
}
