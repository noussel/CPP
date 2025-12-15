/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:33:49 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 10:06:31 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(std::string type){
    this->type = type;
}

const std::string &Weapon::getType()
{
    return(type);
}