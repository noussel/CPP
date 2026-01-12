#include <iostream>
#include "Serializer.hpp"
#include "struct.hpp"


int main()
{
    Data data;

    data.content = "salam"; 

    std::cout << "Adresse originale : " << &data << std::endl;

    uintptr_t entier = Serializer::serialize(&data);
    std::cout << "Valeur serialisée : " << entier << std::endl;

    Data* ptr = Serializer::deserialize(entier);
    std::cout << "Adresse désérialisée : " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "Succès : mêmes adresses" << std::endl;
    else
        std::cout << "Erreur : adresses différentes" << std::endl;

    std::cout << "Valeur dans Data : " << ptr->content << std::endl;

    return 0;
}
