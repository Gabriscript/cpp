/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:07:55 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/12 12:17:31 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), m_name("default") {
    m_attack = FragTrap::m_attack;
    m_energy = ScavTrap::m_energy;
    std::cout << "DiamondTrap default constructor\n";
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), m_name(name) {
    m_attack = FragTrap::m_attack;
    m_energy = ScavTrap::m_energy;
    std::cout << "DiamondTrap named constructor\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
    m_name = copy.m_name;
    std::cout << "DiamondTrap copy constructor\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
    if (this != &src) {
        ClapTrap::operator=(src);
        m_name = src.m_name;
    }
    std::cout << "DiamondTrap Assignment Operator called\n";
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor\n";
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << m_name 
              << " and my ClapTrap name is " << ClapTrap::m_name << "\n";
}
