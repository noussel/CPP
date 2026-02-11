#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>


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
    // Créer un std::set<int> seen;

    // Pour chaque argument :
    // 1. Vérifier que c’est un nombre valide
    // 2. Convertir en int
    // 3. Vérifier overflow / négatif
    // 4. Essayer seen.insert(n)
    //    - si false → Error (doublon)
    // 5. Ajouter n dans vec
    // 6. Ajouter n dans deq

}