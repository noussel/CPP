/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:59 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/29 12:55:49 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
    value = 0;
    std::cout << "default constuctor called \n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &CopiedFrom)
{
    std::cout << "Copy assignment operator called\n";
    if(this != &CopiedFrom)
        this->value = CopiedFrom.value;
    return(*this);
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits memeber function called\n";
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}
Fixed::Fixed(const int integer)
{
    std::cout<<"Int constructor called "<<std::endl;
    value = integer << fractionalBits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called \n";
    value = roundf(num * (1 << fractionalBits));
}

int Fixed::toInt()const
{
    return(value >> fractionalBits);
}

float Fixed::toFloat()const{
    return(float)value / (1 << fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &num) {
    out << num.toFloat();
    return out;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}
