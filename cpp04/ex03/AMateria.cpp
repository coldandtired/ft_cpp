/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:37:49 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 14:14:10 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	isEquipped = false;
	std::cout << "	AMateria constructed" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	isEquipped = false;
	std::cout << "	AMateria constructed" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.getType()), isEquipped(other.isEquipped)
{
	std::cout << "	AMateria copy constructed" << std::endl;	
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		isEquipped = other.isEquipped;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "	AMateria destroyed" << std::endl;	
}

std::string const &AMateria::getType() const
{
	return type;
}

bool AMateria::getEquipped(void)
{
	return isEquipped;
}

void AMateria::setEquipped(bool equip)
{
	isEquipped = equip;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Abstract class used on " << target.getName() << std::endl;
}
