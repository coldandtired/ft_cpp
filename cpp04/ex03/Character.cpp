/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:12:30 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 14:16:25 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
	std::cout << "	Character constructed" << std::endl;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
	std::cout << "	Character constructed" << std::endl;
}

Character::Character(const Character &other) : name(other.getName())
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (materias[i])
			delete(materias[i]);
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	std::cout << "	Character copy constructed" << std::endl;
}
	
Character &Character::operator=(const Character &other)
{
	(void)other;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (materias[i])
			delete(materias[i]);
	}
	std::cout << "	Character destroyed" << std::endl;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Can't equip an imaginary materia!" << std::endl;
		return;
	}	
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!materias[i])
		{
			m->setEquipped(true);
			materias[i] = m;			
			std::cout << "Equipped " << m->getType() << " in slot " << i <<std::endl;
			return;
		}
	}
	std::cout << "There are already 4 materia equipped!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIAS)
	{
		std::cout << "Bad slot index!" << std::endl;
		return;
	}
	if (!materias[idx])
	{
		std::cout << "There is nothing equipped in that slot!" << std::endl;
		return;
	}
	std::cout << "Unequipped " << materias[idx]->getType() << " from slot " << idx << std::endl;
	materias[idx]->setEquipped(false);
	materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_MATERIAS)
	{
		std::cout << "Bad slot index!" << std::endl;
		return;
	}
	if (!materias[idx])
	{
		std::cout << "There is nothing equipped in that slot!" << std::endl;
		return;
	}
	std::cout << getName() << " used " << materias[idx]->getType() << " on " << target.getName() << std::endl;
	materias[idx]->use(target);
}
