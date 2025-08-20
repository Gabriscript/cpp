/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:46:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/05 12:58:15 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	
	std::string status = av[1];
	Harl harl;
	
	harl.complain(status);
	
	return 0;	
}