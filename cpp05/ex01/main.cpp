/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:52 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/15 11:44:59 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Creation and checking" << std::endl;
	try
	{
		Form form("107", 0, 3);
		// Form form("107", 3, 0);
		// Form form("107", 155, 3);
		// Form form("107", 3, 166);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat bc("Ed", 5);
	try
	{
		Form form("106b", 3, 10);
		bc.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Form form("107b", 10, 10);
	bc.signForm(form);
	return 0;
}
