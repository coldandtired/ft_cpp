/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:58 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/15 11:44:06 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	// 1 is best, 150 worst
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade()){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName(void) const
{
	return name;	
}

int	Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::incGrade(void)
{
	// 1 is best
	if (MAX_GRADE == grade)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decGrade(void)
{
	// 150 is worst
	if (MIN_GRADE == grade)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << "Couldn't sign " << form.getName() << " because " << getName() << "'s grade is too low!" << std::endl;
	}	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::flush;
	return os;
}
