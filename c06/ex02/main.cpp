#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = generate();

        std::cout << "Using pointer: ";
        identify(ptr);

        std::cout << "Using reference: ";
        identify(*ptr);

        std::cout << "----------------------" << std::endl;

        delete ptr;
    }

    return 0;
}

// int main(){
//     Base *b = new B();
//     identify(*b);
//     delete b;
//     return 0;
// }
