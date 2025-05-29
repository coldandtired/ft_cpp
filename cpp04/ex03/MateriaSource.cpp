/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:35:37 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 14:49:50 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
	std::cout << "	MateriaSource constructed" << std::endl;	
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (other.materias[i])
			materias[i] = (other.materias[i])->clone();
	}
	std::cout << "	MateriaSource copy constructed" << std::endl;	
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		delete(materias[i]);
		if (other.materias[i])
			materias[i] = (other.materias[i])->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (materias[i])
			delete(materias[i]);
	}
	std::cout << "	MateriaSource destroyed" << std::endl;	
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << "Missing materia!" << std::endl;
		return;
	}
	int nextSlot = -1;
	while (materias[++nextSlot]);
	if (nextSlot > 3)
	{
		std::cout << "Materias full" << std::endl;
		return;
	}
	std::cout << "Learned materia " << materia->getType() << std::endl;
	materias[nextSlot] = materia->clone();
	nextSlot++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type.empty())
	{
		std::cout << "Missing type!" << std::endl;
		return NULL;
	}
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (materias[i] && type == materias[i]->getType())
		{
			std::cout << "Created materia " << type << std::endl;
			return (materias[i]->clone());
		}
	}
	std::cout << "No matching materia" << std::endl;
	return NULL;
}
