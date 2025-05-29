/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:14:08 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 09:49:59 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Pointer identified as A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "Pointer identified as B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "Pointer identified as C" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Identified as A" << std::endl;		
	}
	catch(const std::exception& e) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Identified as B" << std::endl;		
	}
	catch(const std::exception& e) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Identified as C" << std::endl;		
	}
	catch(const std::exception& e) {}
}

int main()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete(ptr);
	}
}
