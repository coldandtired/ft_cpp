/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:52:09 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 11:06:22 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print(int &i)
{
	std::cout << i << std::endl;
}

void	triple(int &i)
{
	i *= 3;
}

void	to_upper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main()
{
	int 	ints[] = {1, 2, 3};
	char	chars[] = {'a', 'b', 'C'};
	
	iter(ints, 3, print);
	iter(ints, 3, triple);
	for (int i = 0; i < 3; i++)
		std::cout << ints[i] << std::endl;
	iter(chars, 3, to_upper);
	for (int i = 0; i < 3; i++)
		std::cout << chars[i] << std::endl;
}
