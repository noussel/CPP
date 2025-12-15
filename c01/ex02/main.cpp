/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:13:21 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 21:20:00 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>



int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "string adress : " << &str << "\n";
    std::cout << "string pointer : " << stringPTR << "\n";
    std::cout << "string reference : " << &stringREF << "\n";
    
    std::cout << "string value : " << str << "\n";
    std::cout << "string pointer value : " << *stringPTR << "\n";
    std::cout << "string reference value : " << stringREF << "\n";
    
}