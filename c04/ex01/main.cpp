#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    std::cout << "\n=== Test tableau d'Animals ===" << std::endl;
    {
        const int size = 4;
        const Animal* animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        for (int i = 0; i < size; i++)
            delete animals[i];
    }

    std::cout << "\n=== Test deep copy Dog ===" << std::endl;
    {
        Dog dog1;
        dog1.setIdeas(0, "I am a Dog");

        Dog dog2 = dog1; 
        dog2.setIdeas(0, "I am an other Dog");
    


        std::cout << "Dog1 idea: " << dog1.getIdeas(0) << std::endl;
        std::cout << "Dog2 idea: " << dog2.getIdeas(0) << std::endl;

    }

        std::cout << "\n=== Test deep copy cat ===" << std::endl;
    {
        Cat cat1;
        cat1.setIdeas(0, "I am a Cat");

        Cat cat2 = cat1;
        cat2.setIdeas(0, "I am an other Cat");
        std::cout << "Dog1 idea: " << cat1.getIdeas(0) << std::endl;
        std::cout << "Dog2 idea: " << cat2.getIdeas(0) << std::endl;

    }




    return 0;
}