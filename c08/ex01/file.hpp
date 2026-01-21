#pragma once
#include <iostream>
#include <vector>

class span {
    private :
        std::vector<int> container;
        unsigned int maxSize;
    public :
        // span();
        span(unsigned int maxSize);
        span(span &other);
        span &operator=(span &other);
        addNumber(int n);//pushback exceptioon
        int shortestSpan();//trier faire la soustractione succesivement
        int longestSpan();//find max then min then faire la soustraction 
        ~span();
};

class fullContainer : public exception {
    const char *what() const throw();
};

class tooSmallSize : public exception {//constructor
    const char *what() const throw();
};

class towMumbers : public exception {
    const char *what() const throw();
};

// Templates non nécessaires ici, Span n’est qu’une classe avec int

// Utiliser les algorithmes STL (sort, min_element, max_element)

// Exceptions propres

// Code simple, lisible, efficace