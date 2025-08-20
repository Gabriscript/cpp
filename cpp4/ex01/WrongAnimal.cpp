/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:23 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:13:54 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("WrongAnimal")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) : m_type(wrongAnimal.m_type)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	if(this !=  &wrongAnimal)
		m_type = wrongAnimal.m_type;
	return *this;
}
	
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "ROAR" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return m_type;
}