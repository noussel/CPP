#include "MutantStack.hpp"




int main()
{
    {
        MutantStack<int> mstack;
    
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        mstack.push(59);
        mstack.push(48);
    
        std::cout << "Top element: " << mstack.top() << std::endl;
    
        // Utiliser l'itération
        std::cout << "Iterating through MutantStack :  ";

        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;
    
        // Test pop
        mstack.pop();
        std::cout << "After pop, top element: " << mstack.top() << std::endl;
    
        std::cout << "Iterating again :   ";

        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        
        std::cout << std::endl;
    }
}

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(2);
//     mstack.push(523);
//     mstack.push(76);
//     mstack.push(23);
//     mstack.push(64);
//     mstack.push(87);
//     mstack.push(45);
//     mstack.push(12);
//     mstack.push(737);
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }
