/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:11:40 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/28 09:46:29 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

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
        this->value = CopiedFrom.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}
Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}