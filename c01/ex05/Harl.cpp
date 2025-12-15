/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:55:39 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 22:11:16 by nel-khad         ###   ########.fr       */
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
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fun_ptr[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    for(int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            (this->*fun_ptr[i])();
            return;
        }   
    }
    std::cout << "Invalide level!" << "\n";
}
