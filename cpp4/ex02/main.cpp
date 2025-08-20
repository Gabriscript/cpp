/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:08 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:43:03 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
//	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
//	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

//	delete animal;
	delete dog;
	delete cat;

	

	return 0;
}