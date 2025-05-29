/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:08:12 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 12:23:27 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "	Ice constructed" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	(void)other;
	std::cout << "	Ice copy constructed" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	std::cout << "Ice assignment" << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "	Ice destroyed" << std::endl;
}

Ice *Ice::clone() const
{
	std::cout << "Cloned ice materia" << std::endl;
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
