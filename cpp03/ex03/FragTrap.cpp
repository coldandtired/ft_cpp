/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:39:09 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 13:21:41 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	damage = 30;	
	std::cout << "FragTrap " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap &other){ *this = other; }

FragTrap &FragTrap::operator=(FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five, guys!" << std::endl;
}
