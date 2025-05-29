/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:40:06 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/17 09:40:00 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false),  signGrade(150), execGrade(150){}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) : name(other.getName()), isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade()){}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		isSigned = other.getIsSigned();
	return *this;
}

AForm::~AForm(){}

std::string AForm::getName(void) const
{
	return name;
}

bool AForm::getIsSigned(void) const
{
	return isSigned;
}

int AForm::getSignGrade(void) const
{
	return signGrade;
}

int AForm::getExecGrade(void) const
{
	return execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
}

void AForm::checkForm(const Bureaucrat &bureaucrat) const
{	
	if (!isSigned)			
		throw FormNotValidException();
	if (bureaucrat.getGrade() > execGrade)
		throw GradeTooLowException();
	std::cout << bureaucrat.getName() << " executed " << getName() << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::FormNotValidException::what() const throw()
{
	return ("Form not signed!");
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	os << form.getName() << ", isSigned: " << form.getIsSigned() << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade() << std::flush;
	return os;
}
