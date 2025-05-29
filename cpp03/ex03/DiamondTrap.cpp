/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:46:56 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:19:46 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap")
{
	(*this).name = name;
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other) : FragTrap(other.getName()), ScavTrap(other.getName())
{	
		name = other.name;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	if (this != &other)
		name = other.name;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << name << " and " << ClapTrap::getName() << std::endl;
}
