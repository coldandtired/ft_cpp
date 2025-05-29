/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:24:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 11:11:13 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "	Cure constructed" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	(void)other;
	std::cout << "	Cure copy constructed" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	std::cout << "Cure assignment" << std::endl;
	return *this;
}

Cure::~Cure()
{
	std::cout << "	Cure destroyed" << std::endl;
}

Cure *Cure::clone() const
{
	Cure *newCure = new Cure();
	std::cout << "Cloned cure materia" << std::endl;
	return (newCure);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
