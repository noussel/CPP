#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    if(this == &other)
        return *this;
    vec = other.vec;
    deq = other.deq;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other){
    *this = other;
}

std::vector<int> &PmergeMe::getVect(){
    return vec;
}

std::deque<int> &PmergeMe::getDeq(){
    return deq;
}

std::ostream &operator<<(std::ostream &out, PmergeMe &p){
    for(size_t i = 0; i < p.getVect().size(); i++){
        out << p.getVect()[i] << " ";
    }
    out << std::endl;

    for(size_t i = 0; i < p.getDeq().size(); i++){
        out << p.getDeq()[i] << " ";
    }
    return out;
}

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

std::vector<size_t> jacobsthal(size_t minSize){
    std::vector<size_t> finalOrder;
    std::vector<size_t> jaco;

    if(minSize == 0)
        return finalOrder;

    finalOrder.push_back(0);

    if(minSize == 1)
        return finalOrder;
        
    //initialiser les 2 premier elemnets de la suite
    jaco.push_back(1);
    jaco.push_back(3);

    while(jaco.back() < minSize)//si back = 43 et min size = 40 l'ordre va stope a 21
    {
    size_t next = jaco[jaco.size() - 1] + 2 * jaco[jaco.size() - 2];
    jaco.push_back(next);
    }

    size_t prev = 1;
    for(size_t i = 1; i < jaco.size(); i++){

        size_t curr = std::min(jaco[i], minSize);
        for(size_t j = curr; j > prev; j--)
            finalOrder.push_back(j - 1);

        prev = curr;
        
    }
    std::cout << "final order : ";
    for(size_t i = 0; i < finalOrder.size(); i++){
        std::cout << finalOrder[i] << "  ";
    }
    std::cout << "\n";
    return finalOrder;
}