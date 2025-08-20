/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:32:11 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/14 11:54:51 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Costructor called" << std::endl;
}
Brain::Brain(Brain &brain)
{
	std::cout << "Brain Copy Costructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		m_ideas[i] = brain.m_ideas[i];
}
Brain  &Brain::operator=(Brain const &brain)
{
	if (this != &brain) 
        for (int i = 0; i < 100; i++)
            m_ideas[i] = brain.m_ideas[i];
			
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain Destrucor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		m_ideas[index] = idea;
}
std::string Brain::getIdea(int index) 
{
	if (index >= 0 && index < 100)
        return m_ideas[index];
    return "";
}