/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:31:44 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 10:57:53 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    m_health = 100;
    m_energy = 100;
    m_attack = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    m_health = 100;
    m_energy = 100; 
    m_attack = 30; 
    std::cout << "FragTrap Constructor for " << m_name << " called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& src)
{
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    std::cout << "FragTrap Assignment Operator called" << std::endl;
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor for " << m_name << " called" << std::endl;
}

void FragTrap:: attack(const std::string &target)
{
	if (m_energy <= 0)
	{
		std::cout << m_name << " has not enough energy" << std::endl;
		return ;
	}
	if (m_health <= 0)
	{
		std::cout << m_name << " has not enough health" << std::endl;
		return ;
	}
	m_energy--;
	std::cout << m_name << " attack "  << target <<  " causing " << m_attack 
			  << " points damage, energy: " << m_energy << std::endl;
	
	
}
void FragTrap::highFiveGuys()
{
	if (m_health <= 0)
	{
		std::cout << m_name << " can't high five because is dead" <<std::endl;
		return ;
	}
	std::cout << m_name << " SuperMega HIGHFIVE on the way" << std::endl;
}