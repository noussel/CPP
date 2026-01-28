#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


class notFound : public std::exception{
    const char *what()const throw();
};

const char *notFound::what()const throw(){
    return "Value not found\n";
}

template <typename T> 

    void easyfind(T &container, int i){
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), i);
    if(it == container.end())
        throw notFound();
}
