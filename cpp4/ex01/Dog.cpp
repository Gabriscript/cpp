/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:39 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:26:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	m_type = "Dog";
	std::cout << "🐶 Dog has come" << std::endl;
}
Dog::Dog(const Dog &dog) : Animal(dog), brain(new Brain(*dog.brain))
{
	m_type = dog.m_type;
	std::cout << "🐶 Dog Copy has come 🐶" << std::endl;
}
Dog& Dog::operator=(const Dog &dog)
{
	if(this !=  &dog)
	{
		Animal::operator=(dog); 
		*brain = *dog.brain;
	}
	return *this;	
}

Dog::~Dog()
{
	delete brain;
	std::cout << "🐶 Dog has gone" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶 WOOF" << std::endl;
}


Brain *Dog::getBrain() const
{
	return brain;
}

std::string Dog::getType( void ) const
{
	return m_type;
}