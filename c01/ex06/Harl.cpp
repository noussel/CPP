/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:08:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 21:24:41 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "Debug Mssage.........\n";
}

void Harl::info()
{
    std::cout << "[ INFO ]\n";
    std::cout << "Info Message...........\n";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n";
    std::cout << "Warning Message...........\n";
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n";
    std::cout << "Error Message.......\n";
}

void Harl::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while(i < 4)
    {
        if(levels[i] == level)
            break;
        i++;
    }
    switch (i)
    {
    case 0: debug();
    case 1: info();
    case 2: warning();
    case 3: error();
        break;
    
    default:
        std::cout << "Invalide level!";
    }
}