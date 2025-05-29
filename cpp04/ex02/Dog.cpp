/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:17:08 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:26:33 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "	Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other)
{
	type = other.type;
	brain = new Brain(*other.getBrain());
	std::cout << "	Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.getType();
		delete(brain);
		brain = new Brain(*other.getBrain());
	}
	return (*this);
}

Dog::~Dog()
{	
	delete(brain);
	std::cout << "	Dog destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return brain;
}
