/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:48:36 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 13:21:47 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	damage = 20;	
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other){ *this = other; }

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		damage = other.damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is guarding the gate!" << std::endl;
}
