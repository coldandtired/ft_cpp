/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:52 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/17 10:32:11 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;
	AForm *form;

	form = intern.makeForm("presidential pardon", "Ed");
	std::cout << form->getName() << std::endl;
	delete(form);
	form = intern.makeForm("robotomy request", "Ed");
	std::cout << form->getName() << std::endl;
	delete(form);
	form = intern.makeForm("shrubbery creation", "Ed");
	std::cout << form->getName() << std::endl;
	delete(form);
	form = intern.makeForm("unknown form", "Ed");
	std::cout << (NULL == form) << std::endl;
	
	return 0;
}
