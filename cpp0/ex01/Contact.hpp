/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:33:30 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/30 11:08:09 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	std:: string firstName;
	std:: string lastName;
	std:: string nickName;
	std:: string phoneNumber;
	std:: string darkSecret;
	

public:
	Contact(void);
	~Contact();
	std::string	GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickName() const;
	std::string GetPhoneNumber() const;
	std::string GetSecret() const;
	void		SetFirstName(std::string name);
	void		SetLastName(std::string surname);
	void		SetNickName(std::string nickname);
	void		SetPhoneNumber(std::string number);
	void		SetSecret(std::string secret);
};


#endif