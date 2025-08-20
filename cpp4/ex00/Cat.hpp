/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:30 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:05 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat :  public Animal
{

public:
	Cat();
	Cat(const Cat &cat);
	Cat& operator=(const Cat &cat);	
	~Cat();

	std::string getType( void ) const;
	void makeSound() const override;
};


