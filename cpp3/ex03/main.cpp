/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:43:41 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 12:22:51 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

int main()
{
   /* std::cout << "========================================\n";
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

    std::cout << "\n========================================\n";
    std::cout << "    TESTING FRAGTRAP FUNCTIONALITY\n";
    std::cout << "========================================\n";
    
    std::cout << "\n--- Creating FragTraps (Watch the construction chain!) ---\n";
    FragTrap basicFrag; 
    FragTrap namedFrag("Goblin_Frag");
    
    std::cout << "\n--- FragTrap Enhanced Combat ---\n";
    std::cout << "Basic FragTrap attacks Goblin (notice higher damage):\n";
    basicFrag.attack("Goblin_Frag");
    
    std::cout << "FragTrap repairs itself:\n";
    basicFrag.beRepaired(2);
    
    std::cout << "FragTrap takes moderate damage (should survive - has 100 HP):\n";
    basicFrag.takeDamage(21);
    
    std::cout << "Damaged FragTrap can still repair:\n";
    basicFrag.beRepaired(22);
    
    std::cout << "FragTrap uses special ability:\n";
    basicFrag.highFiveGuys();
    
    std::cout << "\n--- FragTrap Death Test ---\n";
    std::cout << "Goblin attacks with normal damage:\n";
    namedFrag.attack("Human");
    
    std::cout << "Goblin takes lethal damage:\n";
    namedFrag.takeDamage(101);
    
    std::cout << "Trying to damage a dead FragTrap:\n";
    namedFrag.takeDamage(15); 
    
    std::cout << "Dead FragTrap tries to high five:\n";
    namedFrag.highFiveGuys(); 
    
    std::cout << "Dead FragTrap tries to attack:\n";
    namedFrag.attack("Human"); */
    

	std::cout << "========================================\n";
    std::cout << "    TESTING DIAMONDTRAP FUNCTIONALITY\n";
    std::cout << "========================================\n";

    std::cout << "\n--- Creating DiamondTraps ---\n";
    DiamondTrap defaultDiamond;
    DiamondTrap heroDiamond("Hero");

    std::cout << "\n--- Testing whoAmI() ---\n";
    defaultDiamond.whoAmI();
    heroDiamond.whoAmI();

    std::cout << "\n--- Testing attack() from ScavTrap ---\n";
    heroDiamond.attack("Elf");

    std::cout << "\n--- DiamondTrap combat sequence ---\n";
    heroDiamond.takeDamage(20);
    heroDiamond.beRepaired(10);
    heroDiamond.attack("Elf");

    std::cout << "\n--- Damage to death ---\n";
    heroDiamond.takeDamage(150); 

    std::cout << "Trying to attack while dead:\n";
    heroDiamond.attack("Gnome");

    std::cout << "Trying to repair while dead:\n";
    heroDiamond.beRepaired(50);

    std::cout << "\n--- Testing copy constructor ---\n";
    DiamondTrap copyDiamond(heroDiamond);
    copyDiamond.whoAmI();

    std::cout << "\n--- Testing assignment operator ---\n";
    DiamondTrap assignedDiamond;
    assignedDiamond = defaultDiamond;
    assignedDiamond.whoAmI();

    std::cout << "\n--- End of DiamondTrap tests ---\n";
  
    return 0;
}
