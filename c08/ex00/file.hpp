#pragma once
#include <iostream>
// #include <>


template<typename T> void easyfind(T &container, int i);
class notFound : public std::exception{
    const char *what()const throw();
};

template <typename T> 

    void easyfind(T &container, int i){
    typename T::iterator it = container.begin();
    it = std::find(container.begin(), container.end(), i);
    if(it == container.end())
        throw notFound();
}
