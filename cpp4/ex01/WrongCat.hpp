/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:30 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:35 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat :  public WrongAnimal
{

public:
	WrongCat();
	WrongCat(const WrongCat &wrongCat);
	WrongCat& operator=(const WrongCat &wrongCat);	
	~WrongCat();

	std::string getType( void ) const;
	void makeSound() const ;
};


