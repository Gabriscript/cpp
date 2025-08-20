/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:05:19 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:51:31 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class Brain
{
private:
	std::string m_ideas[100];
	public:
		Brain();
		~Brain();
		Brain(Brain &brain);
		Brain & operator=(Brain const &brain);

	void setIdea(int index, const std::string& idea);
    std::string getIdea(int index);

};

