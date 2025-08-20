/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:30 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:25:07 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat :  public Animal
{
private:
	Brain *brain;	

public:
	Cat();
	Cat(const Cat &cat);
	Cat& operator=(const Cat &cat);	
	~Cat() override;

	std::string getType( void ) const;
	Brain *getBrain() const;
	void makeSound() const override;
};


