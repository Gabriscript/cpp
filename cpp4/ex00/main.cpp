/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:08 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:21:47 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal	*animal = new Animal();
	// Animal	*dog = new Dog();
	// Animal	*cat = new Cat();
	
	// std::cout << dog->getType() << " " << std::endl;
	// std::cout << cat->getType() << " " << std::endl;
	
	// animal->makeSound();
	// dog->makeSound();
	// cat->makeSound();

	// delete animal;
	// delete dog;
	// delete cat;
	
	
	Animal	*dog = new Dog();
	WrongAnimal	*wrongAnimal = new WrongAnimal();
	WrongAnimal	*wrongCat =  new WrongCat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	
	
	
	
	dog->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	
	delete dog;
	delete wrongAnimal;
	delete wrongCat;
	
	
	return 0;
}