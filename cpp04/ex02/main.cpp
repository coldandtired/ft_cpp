/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 11:01:42 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "Creating cat and dog" << std::endl;
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	std::cout << "Destroying cat and dog" << std::endl;
	delete(cat);
	delete(dog);

	// Not allowed
	// Animal *a = new Animal();
	// Animal animal;
}
