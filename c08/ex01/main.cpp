#include <iostream>
#include "Span.hpp"

int main()
{
    {    
        Span sp(5);

        try
        {
            sp.sortedFill(10);
            sp.printContainer();

            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

            sp.addNumber(0);//full container
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    {
        try
        {
            Span small(1);
            small.addNumber(42);

            std::cout << "Shortest Span: " << small.shortestSpan() << std::endl; //tooSmallSize
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    {
        Span sp(100);

        try
        {
            sp.sortedFill(50);
            sp.printContainer();

            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);


// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;

// return 0;
// }