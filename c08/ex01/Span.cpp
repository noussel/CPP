#include "Span.hpp"


const char *fullContainer::what() const throw(){
    return "FULL CONTAINER !\n";
}

const char *tooSmallSize::what() const throw(){
    return "SIZE TOO SMALL !\n";
}

Span::Span(unsigned int maxSize){
    this->maxSize = maxSize;
}

Span::Span(const Span &other){
    maxSize = other.maxSize;
    container = other.container;
}

Span &Span::operator=(const Span &other){
    if(this == &other)
        return *this;
    maxSize = other.maxSize;
    container = other.container;
    return *this;
}

void Span::addNumber(int n){
    if(container.size() >= maxSize)
        throw fullContainer();
    container.push_back(n);
}

int Span::longestSpan(){
    if(container.size() < 2)
        throw tooSmallSize();
    std::vector<int>::iterator minIt = std::min_element(container.begin(), container.end());
    std::vector<int>::iterator maxIt = std::max_element(container.begin(), container.end());
    return *maxIt - *minIt;
}

int Span::shortestSpan(){
    if(container.size() < 2)
        throw tooSmallSize();

    std::vector<int> copy = container;
    std::sort(copy.begin(), copy.end());

    int shortest = INT_MAX;
    int curent = 0;

    for(std::vector<int>::iterator it = copy.begin(); it + 1 != copy.end(); it++){
        curent = *(it+1) - *it;
        if(shortest > curent)
            shortest = curent;
    }
    return shortest;
}

void Span::randomFill(){
    while(container.size() < maxSize){
        addNumber(std::rand());
    }
}

void Span::sortedFill(int num){
    while(container.size() < maxSize){
        addNumber(num);
        num--;
    }
}

    void Span::printContainer(){
        std::vector<int>::iterator i = container.begin();
        std::cout << "Container Members : ";
        for(; i < container.end(); i++){
            std::cout << *i << "  ";
        }
        std::cout << std::endl;
    }

Span::~Span(){}
