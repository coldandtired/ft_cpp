/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:10:38 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/05 10:43:25 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> empty_ints;
	std::cout << "ints size: " << empty_ints.size() << std::endl;

	try
	{
		empty_ints[5] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<int> ints(5);
	std::cout << "ints size: " << ints.size() << std::endl;

	try
	{
		ints[0] = 5;
		ints[5] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (int i = 0; i < 5; i++)
		ints[i] = i + 1;
		
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "ints[" << i << "]: " << ints[i] << std::endl;
		total += ints[i];
	}
	std::cout << "total: " << total << std::endl;
	
	Array<std::string> strings(3);
	strings[1] = "abc";

	Array<int> copy(ints);
	for (int i = 0; i < 5; i++)
		std::cout << "ints[" << i << "]: " << copy[i] << std::endl;

	const Array<int> copy2 = copy;
	for (int i = 0; i < 5; i++)
		std::cout << "ints[" << i << "]: " << copy2[i] << std::endl;
}
