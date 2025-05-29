/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:56:24 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 15:18:53 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	choice;
	
	while (1)
	{
		std::cout << "Please choose ADD, SEARCH, or EXIT: " << std::flush;
		std::getline(std::cin, choice);
		if (std::cin.eof() || choice.empty())
			continue ;
		else if (choice == "ADD")
			phoneBook.add();
		else if (choice == "SEARCH")
			phoneBook.search();
		else if (choice == "EXIT")
			break;
	}
	return (0);
}
