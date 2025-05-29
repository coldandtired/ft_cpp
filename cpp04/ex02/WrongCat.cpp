/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:44:27 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:25:45 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "	Wrong cat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	type = other.type;
	std::cout << "	Wrong cat copy constructed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		type = other.getType();
	return (*this);
}

WrongCat::~WrongCat()
{	
	std::cout << "	Wrong cat destroyed" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong miaow" << std::endl;
}
