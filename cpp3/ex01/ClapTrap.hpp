/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:50:15 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 11:42:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<string>

class ClapTrap
{
  protected:
	std::string m_name;
	int m_health;
	int m_energy;
	int m_attack;
public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string name);
	
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};