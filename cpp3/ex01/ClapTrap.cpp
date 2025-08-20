/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:49:29 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 12:26:28 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"ClapTrap.hpp"

ClapTrap::ClapTrap(): m_name("Human"),m_health(10),m_energy(10),m_attack(0)
{
	std::cout << "ClapTrap Constructor Human called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy) 
    : m_name(copy.m_name), m_health(copy.m_health), 
      m_energy(copy.m_energy), m_attack(copy.m_attack)
{
    std::cout << "ClapTrap Constructor Copy called" << std::endl;
}
ClapTrap::ClapTrap(std::string name): m_name(name), m_health(10), m_energy(10), m_attack(0)
{
	std::cout << "ClapTrap Constructor for the name " << m_name << " called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
    {
        m_attack = src.m_attack;
        m_energy = src.m_energy;
        m_health = src.m_health;
        m_name = src.m_name;
    }
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor " << m_name << " called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if(m_energy <= 0)
	{
		std::cout << "ClapTrap " << m_name << " has not enough energy points" << std::endl;
		return ;
	}
	if(m_health <= 0)
	{
		std::cout << "ClapTrap " << m_name << "has not enough health points" << std::endl;
		return ;
	}
	m_energy--;
	std::cout << "ClapTrap " << m_name << " attacks " << target 
			  << " causing " << m_attack << " points damage! "
			  << "Energy: " <<  m_energy  << std::endl;
			  

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_health <= 0)
	{
		std::cout << "ClapTrap " << m_name <<" is dead already" << std::endl;
		return ;
	}
	m_health -= amount ;
	m_health = (m_health <= 0) ? 0 : m_health;
	std::cout << "ClapTrap " << m_name << " was attacked and lost " << amount 
			  << " health points, he now has " << m_health << " health points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if(m_energy <= 0)
	{
		std::cout  << "ClapTrap " << m_name << " has not enough energy points" << std::endl;
		return ;
	}
	if(m_health <= 0)
	{
		std::cout << "ClapTrap " << m_name <<" has not enough health points" << std::endl;
		return ;
	}
	m_health +=amount;
	m_energy--;
	std::cout << "ClapTrap " << m_name << " restored of " << amount 
			  << " points, his current health now is: " << m_health << "! "
			  << "Energy: " <<  m_energy << std::endl;
}