/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:10:02 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:21:23 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "	Animal constructed" << std::endl;
}

Animal::Animal(Animal &other) : type(other.type)
{
	std::cout << "	Animal copy constructed" << std::endl;
}

Animal &Animal::operator=(Animal &other)
{
	type = other.getType();
	return (*this);
}

Animal::~Animal()
{	
	std::cout << "	Animal destroyed" << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}
