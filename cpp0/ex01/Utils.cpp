/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:37:57 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/31 13:05:10 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool IsNumber(std::string number)
{
	for (size_t i = 0; i < number.length(); i++)
	{
		if(number[i] < '0' || number[i] > '9')
			return false;
	}
	return true;
}
bool IsAlpha(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
			return false;
	}
	return true;
}
static std::string ResizeString(const std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}
int DisplayContacts(Contact contacts[8])
{
    int count = 0;

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::string str = contacts[i].GetFirstName();
        if (!str.empty()) {
            count++;
            std::cout << "|" << std::setw(10) << i + 1
                      << "|" << ResizeString(contacts[i].GetFirstName())
                      << "|" << ResizeString(contacts[i].GetLastName())
                      << "|" << ResizeString(contacts[i].GetNickName())
                      << "|" << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;

    return count;
}

int OverflowHandler(std::string str)

{
	return (str.length() != 1 || !IsNumber(str)) ? -1 : (str[0] - '0');
}
