/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:28:53 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 18:15:10 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
{ 
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club); //car reference doit etre initialize lors de la declaration
    bob.attack(); 
    club.setType("some other type of club"); 
    bob.attack();
}
{ 
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack(); 
    club.setType("some other type of club");
    jim.attack(); 
}
return 0;
}
