/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:09:31 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 18:17:20 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->slah = NULL;
    this->name  = name;
}

void HumanB::setWeapon(Weapon &slah)
{
    this->slah = &slah;
}

void HumanB::attack()
{
    if(slah)
        std::cout << name << " attacks with their " << slah->getType() << "\n";
    else
        std::cout << "has no weapon \n";
}