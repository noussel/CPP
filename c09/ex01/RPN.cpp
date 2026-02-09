#include "RPN.hpp"

RPN::RPN(){}
RPN &RPN::operator=(RPN &other){
    if (this == &other)
    return *this;
    this->container = other.container;
    return *this;
}
RPN::RPN(RPN &other){
    *this = other;
}
RPN::~RPN(){}

int RPN::getResult(char op){
    if(container.size() < 2)
        throw std::runtime_error("Error : Few numbers!\n");
    int a = container.top();
    container.pop();
    int b = container.top();
    container.pop();
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
    {
        if (a == 0)
            throw std::runtime_error("Error : Division on 0 \n");
        return b / a;
    }
    throw std::runtime_error("Error : Invalide operator\n");
}

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
    for(int i = 0; elements[i]; i++){
        if(!isValide(elements[i]))
            throw std::runtime_error("Error : Invalide Element !\n");
        if(std::isdigit(elements[i]))
            container.push(elements[i] - '0');
        else if(isOperator(elements[i])){
            container.push(getResult(elements[i]));//delet 2 elemts top pop
        }
    }
    if (container.size() != 1)
        throw std::runtime_error("Error : Invalide Elemets \n");
    std::cout << container.top() << std::endl;

}
