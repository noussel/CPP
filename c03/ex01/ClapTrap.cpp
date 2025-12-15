/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:48:55 by nel-khad          #+#    #+#             */
/*   Updated: 2025/12/03 10:20:31 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
    Name = "";
    hitPoints = 10;
    energyPoints  = 10;
    attackDamage = 10;
    std::cout << "\033[34m" << "ClapTrap Default constructer\033[0m" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(10){
    
    std::cout << Name << "\033[34m" << " ClapTrap constructer with name\033[0m\n";
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "\033[34m" << "ClapTrap copy constructor \033[0m\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    if(this == &other)
        return *this;
    this->Name = other.Name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if(hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << Name << " attack " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
        return;
    }
    std::cout << "ClapTrap : " << Name << " cannot attack !\n";
}

void ClapTrap::takeDamage(unsigned int amount){
    if(amount >= hitPoints)
        hitPoints = 0;
    else 
        hitPoints -= amount;
    std::cout << Name << " takes : " << amount << " of damage\n";
}

void ClapTrap::beRepaired(unsigned int amount){
    if(energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << Name << " cannot be repaired !\n";
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << Name << " is repaired for : " << amount << std::endl;
}


ClapTrap::~ClapTrap(){
    std::cout  << Name << "\033[31m" << " ClapTrap Destroyed\033[0m\n";
}