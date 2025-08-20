/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:35:54 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/28 11:47:14 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac,char **av)
{
	if (ac > 1)
	{
		std::string upperString;
	
		for (int i = 1; i < ac; i++)
			for (int j = 0; j < av[i][j]; j++)
				upperString += std::toupper(av[i][j]);

		std::cout << upperString << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}