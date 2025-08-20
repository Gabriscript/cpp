/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:29:31 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/05 11:44:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << "[ INVALID ]" << std::endl;
	harl.complain("MEOW");
	
}

