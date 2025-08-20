/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:36 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:11:30 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"


class WrongAnimal
{
protected :
	std::string m_type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &wrongAnimal);
	WrongAnimal& operator=(const WrongAnimal &wrongAnimal);	
	virtual ~WrongAnimal();


	std::string getType( void ) const;
	void makeSound() const;
	
};


