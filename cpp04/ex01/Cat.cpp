/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:14:27 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:26:16 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "	Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other)
{
	type = other.type;
	brain = new Brain(*other.getBrain());
	std::cout << "	Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.getType();
		delete(brain);
		brain = new Brain(*other.getBrain());
	}
	return (*this);
}

Cat::~Cat()
{	
	delete(brain);
	std::cout << "	Cat destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return brain;
}
