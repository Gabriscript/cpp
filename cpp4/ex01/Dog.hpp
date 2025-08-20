/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:35 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:26:36 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Dog :  public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog &dog);
	Dog& operator=(const Dog &dog);	
	~Dog() override;

	std::string getType( void ) const;
	Brain *getBrain() const;
	void makeSound() const override;
};


