#include "whatever.hpp"





int main( void ) {
int a = 2;
int b = 3;
Swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << Min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << Max( a, b ) << std::endl;
std::string c = "cccccccccc";
std::string d = "dddddddddd";
Swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << Min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << Max( c, d ) << std::endl;
return 0;
}