#include "file.hpp"


#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    // ===== Test avec vector =====
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        easyfind(v, 2);
        std::cout << "2 found in vector" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout  << e.what() << std::endl;
    }

    try
    {
        easyfind(v, 42);
        std::cout << "42 found in vector" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // ===== Test avec list =====
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try
    {
        easyfind(l, 20);
        std::cout << "20 found in list" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout <<  << e.what() << std::endl;
    }

    try
    {
        easyfind(l, 99);
        std::cout << "99 found in list" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout <<  << e.what() << std::endl;
    }

    return 0;
}
