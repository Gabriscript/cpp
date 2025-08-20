/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:13:34 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/04 11:26:08 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;
	
public:
	HumanB(std::string name);
	~HumanB();

		void attack();
		void setWeapon(Weapon &weapon);
};




#endif