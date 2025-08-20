/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:35 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:28 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog :  public Animal
{

public:
	Dog();
	Dog(const Dog &dog);
	Dog& operator=(const Dog &dog);	
	~Dog();

	std::string getType( void ) const;
	void makeSound() const override;
};


