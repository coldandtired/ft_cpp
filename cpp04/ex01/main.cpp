/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 10:57:45 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "Creating dog and dog2" << std::endl;
	Dog* dog = new Dog();
	Dog* dog2 = new Dog(*dog);
	dog->getBrain()->getIdeas()[0] = "a dog idea";
	std::cout << "dog's brain address: " << dog->getBrain() << std::endl;
	std::cout << "dog2's brain address: " << dog2->getBrain() << std::endl;
	std::cout << "dog's idea[0]: " << dog->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "dog2's idea[0]: " << dog2->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Destroying dog and dog2" << std::endl;
	delete(dog);
	delete(dog2);

	std::cout << "Creating cat and cat2" << std::endl;
	Cat* cat = new Cat();
	Cat* cat2 = new Cat(*cat);
	cat->getBrain()->getIdeas()[0] = "a cat idea";
	std::cout << "cat's brain address: " << cat->getBrain() << std::endl;
	std::cout << "cat2's brain address: " << cat2->getBrain() << std::endl;
	std::cout << "cat's idea[0]: " << cat->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "cat2's idea[0]: " << cat2->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Destroying cat and cat2" << std::endl;
	delete(cat);
	delete(cat2);

	std::cout << "Creating animals:" << std::endl;
	
	Animal *animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	std::cout << "Destroying animals:" << std::endl;

	for (int i = 0; i < 4; i++)
		delete(animals[i]);
}
