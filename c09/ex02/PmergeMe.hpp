#pragma once
#include <iostream>
#include <vecter>

class  FordJohnson{
    private :
        std::vecter<int> vect;
        std:deque<int> deq;
    public :
        FordJohnson();
        FordJohnson(FordJohnson &other);
        FordJohnson &operator=(FordJohnson &other);
        ~FordJohnson();
}
