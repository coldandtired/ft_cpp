/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:43:20 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/02 10:12:51 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){(void)other;}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm *Intern::makePPF(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRRF(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeSCF(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(Intern::*forms[3])(std::string) = {&Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == form)
			return (this->*forms[i])(target);
	}
	std::cout << "Invalid form!" << std::endl;
	return NULL;
}
