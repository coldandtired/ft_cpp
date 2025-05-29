/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 10:52:54 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* animal = new Animal();
	const Animal* c = new Cat();
	const Animal* d = new Dog();
	std::cout << animal->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	animal->makeSound();
	c->makeSound();
	d->makeSound();

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	const WrongCat* wc2 = new WrongCat();
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	std::cout << wc2->getType() << " " << std::endl;
	wrongAnimal->makeSound();
	wc->makeSound();
	wc2->makeSound();
	
	delete(wc2);
	delete(wc);
	delete(wrongAnimal);
	delete(d);
	delete(c);
	delete(animal);
}
