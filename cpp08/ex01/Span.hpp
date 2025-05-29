/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:58:15 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/05 10:58:03 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdlib>

class Span
{
	private:
		unsigned int		max_numbers;
		std::vector<int>	numbers;
	public:
		Span();
		Span(unsigned int max_numbers);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int num);
		void addNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
	class FullNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Already full!");
			}
		
	};

	class NoSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("No span!");
			}
		
	};
};

#endif
