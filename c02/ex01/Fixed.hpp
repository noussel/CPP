
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
    int value;
    static const int  fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        int getRawBits()const;
        void setRawBits(int const raw);
        Fixed(const int integer);
        Fixed(const float floaat);
        float toFloat(void) const;
        int toInt(void) const;
        ~Fixed();
    };
std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif