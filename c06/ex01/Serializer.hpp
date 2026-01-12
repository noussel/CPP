#pragma once
#include <iostream>
#include <stdint.h>
#include "struct.hpp"

class Serializer{
    private :
        Serializer();// Non instanciable 
        Serializer(Serializer &other);
    
    public :
        Serializer &operator=(Serializer &other);
        static uintptr_t serialize(Data* ptr);//data * -> uintptr
        static Data* deserialize(uintptr_t raw);
        ~Serializer();
};

