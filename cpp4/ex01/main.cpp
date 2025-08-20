/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:08 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 12:33:42 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	size_t size = 10;
	Animal *animals[size];

	for (size_t i = 0; i < size; i++)
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

	for (size_t i = 0; i < size; i++)
		animals[i]->makeSound();

	for (size_t i = 0; i < size; i++)
			delete animals[i];


	/*DEEP COPY TEST*/

	// Dog dog1;

	// dog1.makeSound();

	// dog1.getBrain()->setIdea(0,"Bark");
	// dog1.getBrain()->setIdea(1, "sleep");
	 
	// Dog dog2 = dog1;

	// std::cout << "dog1 idea index 0 : " << dog1.getBrain()->getIdea(0) << std::endl;
	// std::cout << "dog2 idea index 0 : " << dog2.getBrain()->getIdea(0) << std::endl;

	

	return 0;
}