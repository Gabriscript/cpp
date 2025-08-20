/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:23 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:12:07 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
	std::cout << "🐾Animal Constructor called" << std::endl;
}
Animal::Animal(const Animal &animal) : m_type(animal.m_type)
{
	std::cout << "🐾Animal Copy Constructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &animal)
{
	if(this !=  &animal)
		m_type = animal.m_type;
	return *this;
}
	
Animal::~Animal()
{
	std::cout << "🐾Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "🐾ROAR" << std::endl;
}

std::string Animal::getType( void ) const
{
	return m_type;
}