/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:54 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/15 13:49:37 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		static const int	MIN_GRADE = 150;
		static const int	MAX_GRADE = 1;
		const std::string 	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName(void) const;
		int	getGrade(void) const;
		void	incGrade(void);
		void	decGrade(void);
		void	signForm(AForm &form) const;
	
	// exceptions nested in the Bureaucrat class
	// what is the error message to show (C-style string)
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

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
