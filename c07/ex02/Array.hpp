#pragma once
#include <iostream>
#include <exception>

template <typename T> 
class Array
{
    private :
        T *ptr;
        int n;
    public :
        Array(); //empty array;
        Array(int lenght);//array of n elements;
        Array(Array &other);
        Array &operator=(Array &other);
        T &operator[](int i);
        ~Array();
};

template <typename T> 
Array<T>::Array(){
    n = 0;
    ptr = NULL;//[]
}

template <typename T> 
Array<T>::Array(int length){
    if(length < 0)
        throw std::length_error("Invalid array size\n");
    else if (length == 0)
        ptr = NULL;
    else
        ptr = new T[length];
    n = length;
}

template <typename T> 
Array<T>::Array(Array &other){
    n = other.n;
    ptr = new T[other.n];
    for(int i = 0; i < n; i++){
        ptr[i] = other.ptr[i];
    }
}

template <typename T> 
Array<T> &Array<T>::operator=(Array &other){
    delete[] ptr;
    n = other.n;
    ptr = new T[other.n];
        for(int i = 0; i < n; i++){
        ptr[i] = other.ptr[i];
    }
    return *this;
}

template <typename T> 
T &Array<T>::operator[](int i){
    if(i >= n)
        throw std::out_of_range("Index out of bound \n");
    return ptr[i];
}

template <typename T> 
Array<T>::~Array(){
    delete[] ptr;
}