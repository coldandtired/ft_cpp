/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:39:38 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/15 11:27:28 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		static const int	MIN_GRADE = 150;
		static const int	MAX_GRADE = 1;
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		std::string getName() const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
	
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
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
