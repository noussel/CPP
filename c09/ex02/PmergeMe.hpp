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
    public :
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


template <typename container>
void binnarySearch(container &mainlist, int value){
    size_t left = 0;
    size_t right = mainlist.size();
    while(left < right){
        size_t mid = (left + right) / 2;
        if( value > mainlist[mid])
            left = mid + 1;
        else
            right = mid;
    }
    typename container::iterator pos = mainlist.begin() + left;
    mainlist.insert(pos , value);
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
        minlist.push_back(c.size()-1);
    }

    FordJohnson(maxlist);

    //binarry insert with jacobsthal order
    std::vector<size_t> jacOrder = jacobsthal(minlist.size());

    for(size_t i = 0; i < jacOrder.size(); i++)
        binnarySearch(sortedlist, minlist[jacOrder[i]]);
    c = sortedlist;
}

std::vector<size_t> jacobsthal(size_t minSize);


