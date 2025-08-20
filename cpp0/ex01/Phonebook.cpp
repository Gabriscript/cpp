/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:21:50 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/30 14:10:49 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Phonebook.hpp"

Phonebook::Phonebook()
{
	index = 0;
}
Phonebook::~Phonebook()
{
}
void	Phonebook::Add()
{
	std::string str = "";

	do {
		std::cout << "Enter the first name (letters only): ";
		if (!std::getline(std::cin, str))
			std::exit(0);
		
	} while (str.empty() || !IsAlpha(str));
	contacts[index % 8].SetFirstName(str);

	str = "";
	do {
		std::cout << "Enter the last name (letters only): ";
		if (!std::getline(std::cin, str))
			std::exit(0);
			
	}while (str.empty() || !IsAlpha(str));
	contacts[index % 8].SetLastName(str);

	str = "";
	do {
		std::cout << "Enter the nick name: ";
		if (!std::getline(std::cin, str))
			std::exit(0);
		
	}while (str.empty());
	contacts[index % 8].SetNickName(str);

	str = "";
	do {
		std::cout << "Enter a phone number (digits only): ";
		if (!std::getline(std::cin, str))
			std::exit(0);
		
	}while (str.empty() || !IsNumber(str));
	contacts[index % 8].SetPhoneNumber(str);

	str = "";
	do {
		std::cout << "Enter the secret: ";
		if (!std::getline(std::cin, str))
			std::exit(0);
		
	}while (str.empty());
	contacts[index % 8].SetSecret(str);

	index++;	
}

void Phonebook::Search()
{
	int totalContacts = DisplayContacts(contacts);
	if (totalContacts == 0) {
		std::cout << "No contacts found" << std::endl;
		return;
	}
	
	std::string input;
	int index = -1;
	do {
		std::cout << "Choose a contact between 1 and " << totalContacts << " : ";
		if (!std::getline(std::cin, input))
			std::exit(0);
		
		index = OverflowHandler(input);
		index--;
	} while (index < 0 || index >= totalContacts || contacts[index].GetFirstName().empty());

	std::cout << "First Name: " << contacts[index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].GetLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].GetNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].GetPhoneNumber() << std::endl;
	std::cout << "Secret: " << contacts[index].GetSecret() << std::endl;
}

