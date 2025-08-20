/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:43:41 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 11:02:06 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main()
{
    std::cout << "========================================\n";
    std::cout << "    TESTING CLAPTRAP FUNCTIONALITY\n";
    std::cout << "========================================\n";
    
    std::cout << "\n--- Creating ClapTraps ---\n";
    ClapTrap basicClap;   
    ClapTrap namedClap("Ogre"); 
    
    std::cout << "\n--- ClapTrap Combat Test ---\n";
    std::cout << "Basic Clap attacks Ogre:\n";
    basicClap.attack("Ogre");
    
    std::cout << "Ogre takes damage:\n";
    namedClap.takeDamage(5);
    
    std::cout << "Ogre counter-attacks Human:\n";
    namedClap.attack("Human");
    
    std::cout << "Basic Clap takes heavy damage:\n";
    basicClap.takeDamage(10);
    
    std::cout << "Trying to repair a dead Clap:\n";
    basicClap.beRepaired(5);
    
    std::cout << "Living Clap repairs itself:\n";
    namedClap.beRepaired(3);

	return 0;
	
}