/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:21:46 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/31 13:05:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

enum eCommand {
  CMD_ADD,
  CMD_SEARCH,
  CMD_EXIT,
  CMD_WRONG
};


class	Phonebook
{
	private:
		Contact contacts[8];
		int		index;
		
	public:
		Phonebook(void);
		~Phonebook(void);
		void	Add();
		void	Search();
		
};
	
bool	IsNumber(std::string number);
bool	IsAlpha(std::string str);
int		OverflowHandler(std::string str);
int 	DisplayContacts(Contact contacts[8]);
#endif