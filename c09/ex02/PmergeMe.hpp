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
    //creation des paires
    //declaration de 2 containers de type con un pour max et un pour min
    container maxlist;
    container minlist;
    container sortedlist;

    for(int i = 0; i < c.size() - 1; i += 2){
        if(c[i] < c[i+1])
        {
            maxlist.push_back(c[i+1]);
            minlist.push_back(c[i]);
        }
        else
        {
            maxlist.push_back(c[i+1]);
            minlist.push_back(c[i]);
        }
    }
    if(c.size() % 2 != 0){
        minlist.push_back([c.size()-1]);
    }

    FordJohnson(maxlist);

    //binarry insert with jacobsthal order
    std::vector<size_t> jacOrder = jacobsthal(minlist.size());
    sortedlist = binnarySearch(maxlist, minlist, jacOrder)
    c = sortedlist;
}

std::vector &jacobsthal(size_t minSize){
    std::vector<size_t> finalOrder;
    std::vector<size_t> jaco;

    //initialiser les 2 premier elemnets de la suite
    jaco.push_back(1);
    jaco.push_back(3);

    while(jaco.back() < minSize)//si back = 43 et min size = 40 l'ordre va stope a 21
    {
    size_t next = jaco[jaco.size() - 1] + 2 * jaco[jaco.size() - 2];
    jaco.push_back(next);
    }

    size_t prev = 1;
    finalOrder.push_back(0);
    for(size_t i = 1; )
}