/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:06:13 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/17 09:39:39 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),  target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : target(other.getTarget()){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget(void) const
{
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		srand(time(0));
		checkForm(executor);
		std::cout << "Drilling..." << std::endl;
		int randomNum = rand() % 2;
		std::string message = randomNum == 0 ? "failed!" : "succeeded!";
		std::cout << getTarget() << " robotomy " << message <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
