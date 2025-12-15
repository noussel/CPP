/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:51:11 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/22 21:20:53 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "TRY : ./replace <filename> <s1> <s2>\n";
        return(1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if(s1.empty())
    {
        std::cout << "ERROR : s1 is empty!\n";
        return(1);
    }
    
    std::ifstream infile(av[1]);
    if(!infile)
    {
        std::cout << "infile cant be opened!\n";
        return(1);
    }
    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if(!outfile)
    {
        std::cout << "outfile cant created!\n";
        return(1);
    }
    std::string line;
    bool firstLine = true;
    while(std::getline(infile, line))
    {
        if (!firstLine)
           outfile << "\n";

        firstLine = false;
        size_t pos = 0;
        while((pos = line.find(av[2], pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s1.length();
        }
        
        outfile << line ;
    }
    return(0);
}