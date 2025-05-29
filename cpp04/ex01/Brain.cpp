/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:03:43 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 10:58:07 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = "An idea";
	std::cout << "	Brain constructed" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::string *otherIdeas = other.getIdeas();
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = otherIdeas[i];
	std::cout << "	Brain copy constructed" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::string *otherIdeas = other.getIdeas();
	for (int i = 0; i < 100; i++)
		ideas[i] = otherIdeas[i];
	return (*this);
}

Brain::~Brain()
{	
	delete[]ideas;
	std::cout << "	Brain destroyed" << std::endl;
}

std::string *Brain::getIdeas(void) const
{
	return ideas;
}
