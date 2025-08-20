/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:22:00 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/01 10:41:05 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Phonebook.hpp"



static eCommand GetCommand(const std::string input)
{
	if (input == "ADD")
		return CMD_ADD;
	else if (input == "SEARCH")
		return CMD_SEARCH;
	else if (input == "EXIT")
		return CMD_EXIT;
	else
		return CMD_WRONG;

}
int main()
{
	std::string	input = "";
	Phonebook	phonebook;
	eCommand	cmd;
	
	do {
		std::cout << "Type in one of the following command\n";
		std::cout << "ADD\nSEARCH\nEXIT" << std::endl;
		 if (!std::getline(std::cin, input))
		 	std::exit(0);

		cmd = GetCommand(input);
		switch (cmd)
		{
		case CMD_ADD:
			phonebook.Add();
			break;
		case CMD_SEARCH:
			phonebook.Search();
			break;
		case CMD_EXIT:
			std::cout  << "Exiting" << std::endl;
			break;
		default:
			std::cout << "Input not recognized" << std::endl;
			break;
		}
	} while (cmd != CMD_EXIT);

	return 0;
}
