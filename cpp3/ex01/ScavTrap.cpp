/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:13:20 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 10:24:55 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    m_health = 100;
    m_energy = 50;
    m_attack = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    m_health = 100;
    m_energy = 50; 
    m_attack = 20; 
    std::cout << "ScavTrap Constructor for " << m_name << " called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    std::cout << "ScavTrap Assignment Operator called" << std::endl;
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor for " << m_name << " called" << std::endl;
}

void ScavTrap:: attack(const std::string &target)
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
void ScavTrap::guardGate()
{
	if (m_health <= 0)
	{
		std::cout << "GuardKeeper mode OFF " << m_name << " is dead" <<std::endl;
		return ;
	}
	std::cout << m_name << "GuardKeeper mode ON " << std::endl;
}