/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:59 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/29 13:01:31 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
    value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &CopiedFrom)
{
        if(this != &CopiedFrom)
    this->value = CopiedFrom.value;
    return(*this);
}

int Fixed::getRawBits(void) const{
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed::Fixed(const int integer)
{
    value = integer << fractionalBits;
}

Fixed::Fixed(const float num)
{
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

bool Fixed::operator>(const Fixed &other)const {
    return this->value > other.value;
}

bool Fixed::operator>=(const Fixed &other)const{
    return this->value >= other.value;
}

bool Fixed::operator<(const Fixed &other)const{
    return this->value < other.value;
}

bool Fixed::operator<=(const Fixed &other)const{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other)const{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other)const{
    return this->value != other.value;
}

Fixed Fixed::operator*(const Fixed &other)const{
    Fixed result;
    result.setRawBits((this->value * other.value) >> fractionalBits);//devision
    return result;
}

Fixed Fixed::operator+(const Fixed &other)const{
    Fixed result;
    result.setRawBits(this->value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &other)const{
    Fixed result;
    result.setRawBits(this->value - other.value);
    return result;
}

Fixed Fixed::operator/(const Fixed &other)const{//<< fractianl
    Fixed result;
    result.setRawBits((this->value << fractionalBits) / other.value);//(1000 * 256 ) / 300 = 88,33
    return result;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    if(a < b)
        return(b);
    return(a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if(a < b)
        return(b);
    return(a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    if(a > b)
        return(b);
    return(a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if(a > b)
        return(b);
    return(a);
}

Fixed &Fixed::operator++(){
    ++value;
    return *this;
}

Fixed &Fixed::operator--(){
    --value;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    --value;
    return(tmp);
}

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    ++value;
    return(tmp);
}

Fixed::~Fixed(){

}
