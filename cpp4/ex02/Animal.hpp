/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:36 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:38:12 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"


class Animal
{
protected :
	std::string m_type;
public:
	Animal();
	Animal(const Animal &animal);
	Animal& operator=(const Animal &animal);	
	virtual ~Animal();


	virtual std::string getType( void ) const;
	virtual void makeSound() const = 0;
};


