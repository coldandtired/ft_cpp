/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:05:40 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/17 09:39:42 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137),  target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : target(other.getTarget()){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkForm(executor);
		std::string fileName = getTarget() + "_shrubbery";
		std::ofstream shrubberyFile(fileName.c_str());
		shrubberyFile << "  *      *" << std::endl;
		shrubberyFile << " * *    * *" << std::endl;
		shrubberyFile << "*   *  *   *" << std::endl;
		shrubberyFile << " | |    | |" << std::endl;
		shrubberyFile.close();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

