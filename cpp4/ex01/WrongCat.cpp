/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:43 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:14:10 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	m_type = "WrongCat";
	std::cout << "🐱 WrongCat has come" << std::endl;
}
WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal()
{
	m_type = wrongCat.m_type;
	std::cout << "🐱 WrongCat Copy has come 🐱" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &wrongCat)
{
	if(this !=  &wrongCat)
		WrongAnimal::operator=(wrongCat); 
	return *this;	
}
WrongCat::~WrongCat()
{
	std::cout << "🐱 WrongCat has gone" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "🐱 MEEAAOOWW" << std::endl;
}
std::string WrongCat::getType( void ) const
{
	return m_type;
}