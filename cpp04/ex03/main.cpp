/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:24:42 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 14:53:53 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main(void)
{
	std::cout << "MateriaSource tests" << std::endl;
	MateriaSource ms;
	// bad params
	ms.createMateria("");
	ms.createMateria("abc");
	ms.learnMateria(NULL);

	// learning
	AMateria *ice = new Ice();
	ms.learnMateria(ice);
	
	MateriaSource *ms2 = new MateriaSource(ms);	
	AMateria *newMateria = ms2->createMateria("ice");
	std::cout << newMateria->getType() << std::endl;
	ms.learnMateria(ice);
	AMateria *cure = new Cure();
	ms.learnMateria(cure);	
	ms.learnMateria(ice);

	// too many materias
	ms.learnMateria(ice);
	ms.learnMateria(cure);
	
	std::cout << "Character tests" << std::endl;
	Character c("Ed");
	Character t("Eddy");

	c.equip(NULL);
	c.equip(ice);
	c.equip(cure);
	c.equip(new Ice());
	c.equip(new Cure());
	
	// too many
	c.equip(ice);
	c.equip(cure);

	c.unequip(-1);
	c.unequip(5);

	c.unequip(0);
	c.unequip(0);

	c.use(0, t);
	c.use(-1, t);
	c.use(5, t);
	c.use(1, t);
	c.use(2, t);

	// destroying
	delete(newMateria);
	if (!cure->getEquipped())
		delete(cure);
	if (!ice->getEquipped())
		delete(ice);
	delete(ms2);
	
	std::cout << "Creating a MateriaSource and two Materias" << std::endl;
	
	IMateriaSource *src = new MateriaSource();
	AMateria *mIce = new Ice();
	AMateria *mCure = new Cure();
	src->learnMateria(mIce);
	src->learnMateria(mCure);

	std::cout << "Creating a character and a Materia to equip" << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << "Creating a target character" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete(mCure);
	delete(mIce);
	delete src;
	
	return 0;
}
