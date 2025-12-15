/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:22:33 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 21:29:08 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
    Zombie a("nouss");//detruire a la fin du main
    a.announce();
    Zombie *b;
    b = newZombie("koukou"); //detruire a delete
    b->announce();
    randomChump("hanane"); //detruit a la fin de la fonction 
    delete b;
}
