#pragma once
#include <iostream>
#include <cctype>

// 5 1 2 + 4 * + 3 -
// 5 3 4 * + 3 -
// 5 12 + 3 -
// 17 3 -
// 14
// 5 + ((1 + 2) * 4) - 3
class RPN {
    // parse calculate afficher 
    private :
    std::stack<unsigned int> container;

    public :
    RPN();
    RPN(RPN &other);
    RPN &operator=(RPN &other);
    ~RPN();
    bool isValide(char c);
    bool isOperator(char c);
    int getResult(char operator)
    void calculater(char *elements);
};


bool RPN::isOperator(char c){
    if(c == '+' || c == '-' || c == '/' || c == '*')
        return true;
    return false;
}
bool RPN::isValide(char c){
    if(c == ' ' || isdigit(c) || isOperator(c))
        return true;
    return false;
}

void RPN::calculater(char *elements){
    for(int i; elements[i]; i++){
        if(!isValide(elements[i]))
            throw run_time_error("Error : Invalide Element !\n");
        if(std::isdigit(elements[i]))
            container.push(std::atoi(elements[i]));
        else if(isOperator(elements[i])){
            if(container.size() < 2)
                throw run_time_error("Error :Invalide Input !\n");
            container.push(getResult(elements[i]));//delet 2 elemts top pop
        }
    }
    if (container.size() != 1)
        throw run_time_error("Error : Invalide result \n");
}

RPN::RPN(){}
RPN::~RPN(){}
RPN &RPN::operator=(RPN &other){
    if (this == &other)
        return *this;
    this->container = other.container;
}
RPN::RPN(RPN &other){
    *this = other;
}
















// Le programme doit afficher Error si :

// expression invalide
// pas assez d’opérandes
// division par zéro
// caractères non autorisés
// pile finale ≠ 1 élément