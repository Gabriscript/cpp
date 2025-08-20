/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:37:43 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/01 11:14:16 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*new_zombie = newZombie("Zac");
	new_zombie->announce();
	randomChump("Randal");
	delete new_zombie;
	return 0;
}