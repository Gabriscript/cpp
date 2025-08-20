/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:43 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:00:59 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
Cat::Cat() : Animal()
{
	m_type = "Cat";
	std::cout << "🐱 Cat has come" << std::endl;
}
Cat::Cat(const Cat &cat) : Animal(cat)
{
	m_type = cat.m_type;
	std::cout << "🐱 Cat Copy has come 🐱" << std::endl;
}
Cat& Cat::operator=(const Cat &cat)
{
	if(this !=  &cat)
	Animal::operator=(cat); 
	return *this;	
}

Cat::~Cat()
{
	std::cout << "🐱 cat has gone" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱 MEEAAOOWW" << std::endl;
}

std::string Cat::getType( void ) const
{
	return m_type;
}