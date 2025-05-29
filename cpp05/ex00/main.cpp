/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:52 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/14 15:38:12 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Creation and checking" << std::endl;

	Bureaucrat bc("Ed", 5);
	Bureaucrat *bc2 = new Bureaucrat(bc);
	bc.incGrade();
	bc2->decGrade();
	std::cout << bc << std::endl;
	std::cout << *bc2 << std::endl;
	delete(bc2);

	std::cout << "Exception checking" << std::endl;
	try
	{
		Bureaucrat bc3("Ed", 0);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bc3("Ed", 155);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bc3("Ed", 1);
		bc3.incGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bc3("Ed", 150);
		bc3.decGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
