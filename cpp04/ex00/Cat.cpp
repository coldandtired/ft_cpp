/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:14:27 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:25:24 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "	Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other)
{
	type = other.type;	
	std::cout << "	Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		type = other.getType();
	return (*this);
}

Cat::~Cat()
{	
	std::cout << "	Cat destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaow" << std::endl;
}
