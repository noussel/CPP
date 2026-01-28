#pragma once
#include "limits.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Span {
    private :
        std::vector<int> container;
        unsigned int maxSize;
    public :
        Span(unsigned int maxSize);
        Span(const Span &other);
        Span &operator=(const Span &other);
        void addNumber(int n);
        void randomFill();
        void sortedFill(int n);
        void printContainer();
        int shortestSpan();
        int longestSpan();
        ~Span();
};

class fullContainer : public std::exception {
    const char *what() const throw();
};

class tooSmallSize : public std::exception {
    const char *what() const throw();
};
