#include <iostream>
#include "Fixed.hpp"


// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

#include "Fixed.hpp"
#include <iostream>

int main() {

    std::cout << "\n--- Basic constructors ---\n";
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n--- Assignment ---\n";
    a = Fixed(1234.4321f);
    std::cout << "a = " << a << std::endl;

    std::cout << "\n--- Comparison operators ---\n";
    Fixed x(5.5f);
    Fixed y(10.25f);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x > y : " << (x > y) << std::endl;
    std::cout << "x < y : " << (x < y) << std::endl;
    std::cout << "x >= y : " << (x >= y) << std::endl;
    std::cout << "x <= y : " << (x <= y) << std::endl;
    std::cout << "x == y : " << (x == y) << std::endl;
    std::cout << "x != y : " << (x != y) << std::endl;

    std::cout << "\n--- Arithmetic operators ---\n";
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n--- Increment / Decrement ---\n";
    Fixed e;

    std::cout << "e = " << e << std::endl;
    std::cout << "++e = " << ++e << std::endl;
    std::cout << "e++ = " << e++ << std::endl;
    std::cout << "after e++ = " << e << std::endl;

    std::cout << "--e = " << --e << std::endl;
    std::cout << "e-- = " << e-- << std::endl;
    std::cout << "after e-- = " << e << std::endl;

    std::cout << "\n--- Min / Max ---\n";
    Fixed m1(1.5f);
    Fixed m2(7.75f);

    std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

    std::cout << "\n--- ToFloat / ToInt ---\n";
    Fixed z(8.75f);

    std::cout << "z = " << z << std::endl;
    std::cout << "z.toInt() = " << z.toInt() << std::endl;
    std::cout << "z.toFloat() = " << z.toFloat() << std::endl;

    return 0;
}
