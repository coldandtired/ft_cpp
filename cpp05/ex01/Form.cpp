/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:40:06 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/15 11:25:24 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false),  signGrade(150), execGrade(150){}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form &other) : name(other.getName()), isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade()){}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		isSigned = other.getIsSigned();
	return *this;
}

Form::~Form(){}

std::string Form::getName(void) const
{
	return name;
}

bool Form::getIsSigned(void) const
{
	return isSigned;
}

int Form::getSignGrade(void) const
{
	return signGrade;
}

int Form::getExecGrade(void) const
{
	return execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << form.getName() << ", isSigned: " << form.getIsSigned() << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade() << std::flush;
	return os;
}
