/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:47:07 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/28 09:59:32 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "fixed.hpp"

int main( void ) {
Fixed a; 
Fixed b( a );
Fixed c ;
c = b;
std::cout << a.getRawBits() << std::endl; 
std::cout << b.getRawBits() << std::endl; 
std::cout << c.getRawBits() << std::endl;
return 0; 
}