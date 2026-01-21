#include <iostream>
#include "Array.hpp"


// int main(){
//     try{
//         Array<int> a(3);
//         Array<float> f(5);
//         Array<std::string> s(5);

//         std::cout << a[2] << "\n";
//         std::cout << f[2] << "\n";
//         std::cout << s[0] << "\n";

//         a[0] = 10;
//         a[1] = 20;
//         a[2] = 30;

//         std::cout << a[0] << " _ " << a[1] << " _ " << a[2] << std::endl;

//         // copy constructor 
//         Array<int> b(a);

//         std::cout << "a[1] = " << a[1] << " " << "(" << &a[1] << ")" << std::endl;
//         std::cout << "b[1] = " << b[1] << " " << "(" << &b[1] << ")" << std::endl;

//         //out of range
//         std::cout << a[5] << std::endl;

//         //invalid length
//         Array<int> c(-2);
//     }
//     catch (std::exception &e)
//     {
//         std::cerr << e.what();
//     }
//     return 0;
// }

int main(){
    try{
        Array<std::string> a(3);

        std::cout << a[0] << "\n";

        a[0] = "hi";
        a[1] = "hello";
        a[2] = "hey";

        std::cout << a[0] << " _ " << a[1] << " _ " << a[2] << std::endl;

        // copy constructor 
        Array<std::string> b(a);

        std::cout << "a[1] = " << a[1] << " " << "(" << &a[1] << ")" << std::endl;
        std::cout << "b[1] = " << b[1] << " " << "(" << &b[1] << ")" << std::endl;

        //out of range
        std::cout << a[3] << std::endl;

        //invalid length
        Array<std::string> c(-2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
    return 0;
}
