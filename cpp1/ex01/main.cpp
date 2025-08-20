/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:16:22 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/01 13:31:16 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool IsNumber(std::string number)
{
	for (size_t i = 0; i < number.length(); i++)
	{
		if(number[i] < '0' || number[i] > '9')
			return false;
	}
	return true;
}
static int AmountHandler(std::string str)
{
	return (str.length() != 1  || !IsNumber(str)) ? 0 : (str[0] - '0');
}
int main()
{
	std::string zombieAmount = "";
	int number = 0;
	Zombie *zombies;
	
	do
	{
		std::cout << "Choose amount of zombies for you horde(a number between 1 and 9): " << std::endl;
		if (!std::getline(std::cin, zombieAmount))
			std::exit(0);
		number = AmountHandler(zombieAmount);
				
	} while (!number);

	zombies = zombieHorde(number, "Zombie");
	for (int i = 0; i < number; i++)
	{
		    std::cout  << i + 1 << ": ";
	  		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}