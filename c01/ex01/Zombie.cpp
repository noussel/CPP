/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:15:48 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 11:01:07 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; 
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
std::string Zombie::getName()
{
    return name;
}