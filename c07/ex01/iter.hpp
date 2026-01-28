#pragma once
#include <iostream>


template <typename T> void display(T x){
    std::cout << "~ " << x << std::endl;
}

template <typename T> 
void iter(T *array,size_t const length,void (*f)(T))
{
    for(size_t i = 0; i < length; i++){
        f(array[i]);
    }
}