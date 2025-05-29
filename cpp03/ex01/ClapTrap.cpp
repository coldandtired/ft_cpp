/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:17:42 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/10 16:34:46 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	hitPoints = 10;
	energyPoints = 10;
	damage = 0;
	std::cout << "ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	hitPoints = 10;
	energyPoints = 10;
	damage = 0;
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other) : name(other.name),	hitPoints(other.hitPoints),	energyPoints(other.energyPoints), damage(other.damage){}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	ClapTrap temp(other);
    std::swap(name, temp.name);
    std::swap(hitPoints, temp.hitPoints);
    std::swap(energyPoints, temp.energyPoints);
    std::swap(damage, temp.damage);
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

std::string	ClapTrap::getName()
{
	return (name);
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	std::cout << name << " takes " << amount << " points of damage!" << std::endl;
	if (hitPoints <= 0)
		std::cout << "...and dies!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << name << " heals " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " doesn't have enough energy to heal!" << std::endl;
}
