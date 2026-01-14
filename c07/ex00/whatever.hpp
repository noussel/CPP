#pragma once
#include <iostream>

template <typename T> T Max(T &x, T &y)
{
    if(x == y)
        return y;
    return(x > y ? x : y );
}

template <typename T> T Min(T &x, T &y)
{
    if(x == y)
        return y;
    return(x < y ? x : y );
}

template <typename T> void Swap(T &x, T &y){
    T tmp = y;
    y = x;
    x = tmp;
}