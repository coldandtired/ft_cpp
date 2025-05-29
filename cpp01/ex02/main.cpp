/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:56:28 by lwillis           #+#    #+#             */
/*   Updated: 2025/01/24 14:11:17 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

// REF must be assigned at declaration, and points to str
// PTR can be assigned and reassigned later, and points to the address of str
int	main(void)
{
	std::string str;
	std::string	*stringPTR;
	std::string	&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "Adresses:" << std::endl;
	std::cout << std::setw(11) << "str: " << &str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << std::setw(11) << "str: " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}
