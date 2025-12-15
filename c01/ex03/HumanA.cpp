/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:20:31 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 21:46:14 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &slah): slah(slah)
{
    this->name = name;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << slah.getType() << "\n";
}