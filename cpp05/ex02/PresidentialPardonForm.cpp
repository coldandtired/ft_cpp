/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:07:29 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/17 09:39:28 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),  target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : target(other.getTarget()){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget(void) const
{
	return target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkForm(executor);
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
