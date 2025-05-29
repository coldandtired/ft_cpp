/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:17:08 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:25:31 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "	Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other)
{
	type = other.type;
	std::cout << "	Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		type = other.getType();
	return (*this);
}

Dog::~Dog()
{	
	std::cout << "	Dog destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
