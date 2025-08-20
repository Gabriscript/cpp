/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:37:48 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/01 12:06:43 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) 
{
	_name = name;
	std::cout << name << " the zombie raises from the graveyard" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << _name << " the zombie go back in his coffin" << std::endl;
}
void Zombie::announce( void )
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}