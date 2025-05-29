/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:39:38 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/15 13:58:50 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		static const int	MIN_GRADE = 150;
		static const int	MAX_GRADE = 1;
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	protected:
		void				checkForm(const Bureaucrat &Bureaucrat) const;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		std::string getName() const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();		
	};

	class FormNotValidException : public std::exception
	{
		public:
			const char *what() const throw();		
	};
};

std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif
