#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <algorithm>


class  PmergeMe{
    private :
        std::vector<int> vec;
        std::deque<int>  deq;

    public :
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void parseInput(char **av);//check for duplication (usint std::set)& fill out the container 

        template <typename container> 
        void FordJohnson(container &c);//sorting algorithme -> create paires -> put max and min -> sort max values -> put min using binary search
};

void PmergeMe::parseInput(char **av){
    std::set<int> s;
    for(int i = 1; av[i]; i++){
        for(int j = 0; av[i][j]; j++){
            if(!isdigit(av[i][j]))
                throw std::runtime_error("Error : Invalide element\n");
        }
        long n = std::atol(av[i]);

        if(n > INT_MAX || n < 0)
            throw std::runtime_error("Error : Invalide number\n");
        if(!s.insert(n).second)//insert return un paire first = iteratur, second = bool
            throw std::runtime_error("Error : Duplicated number\n");
        vec.push_back(n);
        deq.push_back(n);
    }
}

template <typename container>
void PmergeMe::FordJohnson(container &c){

}