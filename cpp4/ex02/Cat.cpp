/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:43 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:25:42 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
Cat::Cat() : Animal(), brain(new Brain())
{
	m_type = "Cat";
	std::cout << "🐱 Cat has come" << std::endl;
}
Cat::Cat(const Cat &cat) : Animal(cat), brain(new Brain(*cat.brain))
{
	m_type = cat.m_type;
	std::cout << "🐱 Cat Copy has come 🐱" << std::endl;
}
Cat& Cat::operator=(const Cat &cat)
{
	if(this !=  &cat)
	{
		Animal::operator=(cat);
		*brain = *cat.brain; 
	}
	return *this;	
}

Cat::~Cat()
{
	delete brain;
	std::cout << "🐱 cat has gone" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱 MEEAAOOWW" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}

std::string Cat::getType( void ) const
{
	return m_type;
}