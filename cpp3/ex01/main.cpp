/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:43:41 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 11:01:49 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


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
    
    std::cout << "\n========================================\n";
    std::cout << "    TESTING SCAVTRAP FUNCTIONALITY\n";
    std::cout << "========================================\n";
    
    std::cout << "\n--- Creating ScavTraps (Watch the construction chain!) ---\n";
    ScavTrap basicScav; 
    ScavTrap namedScav("Goblin_Scav");
    
    std::cout << "\n--- ScavTrap Enhanced Combat ---\n";
    std::cout << "Basic ScavTrap attacks Goblin (notice higher damage):\n";
    basicScav.attack("Goblin_Scav");
    
    std::cout << "ScavTrap repairs itself:\n";
    basicScav.beRepaired(2);
    
    std::cout << "ScavTrap takes moderate damage (should survive - has 100 HP):\n";
    basicScav.takeDamage(21);
    
    std::cout << "Damaged ScavTrap can still repair:\n";
    basicScav.beRepaired(22);
    
    std::cout << "ScavTrap uses special ability:\n";
    basicScav.guardGate();
    
    std::cout << "\n--- ScavTrap Death Test ---\n";
    std::cout << "Goblin attacks with normal damage:\n";
    namedScav.attack("Human");
    
    std::cout << "Goblin takes lethal damage:\n";
    namedScav.takeDamage(101);
    
    std::cout << "Trying to damage a dead ScavTrap:\n";
    namedScav.takeDamage(15); 
    
    std::cout << "Dead ScavTrap tries to guard:\n";
    namedScav.guardGate(); 
    
    std::cout << "Dead ScavTrap tries to attack:\n";
    namedScav.attack("Human"); 
    
    std::cout << "\n--- End of Tests (Watch destruction chain!) ---\n";
    
    return 0;
}