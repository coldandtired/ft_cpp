/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:33:36 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/07 09:45:36 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	Parser parser;

	if (2 != argc)
	{
		std::cerr << "Bad argument" << std::endl;
		return 1;
	}

	try
	{
		if (!parser.parseLine(argv[1]))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
