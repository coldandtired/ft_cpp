/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:52 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/17 09:41:46 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void unSigned()
{
	std::cout << "Not signed" << std::endl;
	Bureaucrat bc("Ed", 1);
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("Ed-209");
	PresidentialPardonForm ppf("Johnny");
	
	try
	{
		scf.execute(bc);
	}
	catch(const AForm::FormNotValidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		rrf.execute(bc);
	}
	catch(const AForm::FormNotValidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		ppf.execute(bc);
	}
	catch(const AForm::FormNotValidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void tooLow()
{
	std::cout << "Too low grade" << std::endl;
	Bureaucrat bc("Ed", 150);
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("Ed-209");
	PresidentialPardonForm ppf("Johnny");
	
	try
	{
		bc.signForm(scf);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bc.signForm(rrf);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bc.signForm(ppf);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void success()
{
	std::cout << "Successful" << std::endl;
	Bureaucrat bc("Ed", 1);
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("Ed-209");
	PresidentialPardonForm ppf("Johnny");

	bc.signForm(scf);
	bc.signForm(rrf);
	bc.signForm(ppf);
	scf.execute(bc);
	rrf.execute(bc);
	ppf.execute(bc);
}

int	main(void)
{
	tooLow();
	unSigned();
	success();
	
	return 0;
}
