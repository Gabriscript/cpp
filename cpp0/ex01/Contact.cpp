/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:22:10 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/31 12:46:22 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{	
}

Contact::~Contact()
{	
}
std::string  Contact::GetFirstName() const
{
	return firstName;
}

std::string Contact::GetLastName() const
{
	return lastName;
}

std::string Contact::GetNickName() const
{
	return nickName;
}

std::string Contact::GetPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::GetSecret() const
{
	return darkSecret;
}

void	Contact::SetFirstName(std::string name)
{
	firstName = name;
}
void	Contact::SetLastName(std::string surname)
{
	lastName  = surname;
}
void	Contact::SetNickName(std::string nickname)
{
	nickName = nickname;
}
void	Contact::SetPhoneNumber(std::string number)
{
	phoneNumber = number;	
}
void	Contact::SetSecret(std::string secret)
{
	darkSecret = secret;
}


