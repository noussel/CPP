#pragma once
#include <iostream>
#include <cctype>
#include <stack>
#include <cstdlib>


// 5 1 2 + 4 * + 3 -
// 5 3 4 * + 3 -
// 5 12 + 3 -
// 17 3 -
// 14
// 5 + ((1 + 2) * 4) - 3

class RPN {
    private :
    std::stack<unsigned int> container;

    public :
    RPN();
    RPN(RPN &other);
    RPN &operator=(RPN &other);
    ~RPN();
    bool isValide(char c);
    bool isOperator(char c);
    int getResult(char op);
    void calculater(char *elements);
};
















// Le programme doit afficher Error si :

// expression invalide
// pas assez d’opérandes
// division par zéro
// caractères non autorisés
// pile finale ≠ 1 élément