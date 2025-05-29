/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:10:30 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 13:56:49 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int> ints;
	ints.push_front(1);
	ints.push_front(3);
	ints.push_front(5);
	ints.push_front(2);
	ints.push_front(4);

	std::vector<int> ints2;
	ints2.push_back(1);
	ints2.push_back(3);
	ints2.push_back(5);
	ints2.push_back(2);
	ints2.push_back(4);

	try
	{
		std::list<int>::iterator item = easyfind(ints, 3);
		std::cout << *item << std::endl;
		item = easyfind(ints, 4);
		std::cout << *item << std::endl;
		item = easyfind(ints, 7);
		std::cout << *item << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator item = easyfind(ints2, 3);
		std::cout << *item << std::endl;
		item = easyfind(ints2, 4);
		std::cout << *item << std::endl;
		item = easyfind(ints2, 7);
		std::cout << *item << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
