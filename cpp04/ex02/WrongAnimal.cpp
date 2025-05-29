/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:43:42 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:25:40 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "	Wrong animal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "	Wrong animal copy constructed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type = other.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{	
	std::cout << "	Wrong animal destroyed" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal noise" << std::endl;
}
