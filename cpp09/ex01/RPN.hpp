/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:23:05 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/07 09:14:44 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class Parser
{
	private:
		std::stack<int>	values;
		int				total;
		int 			calculate(int a, int b, char sign);
		bool 			start();
	public:
		Parser();
		Parser(const Parser &other);
		Parser &operator=(const Parser &other);
		~Parser();
		bool parseLine(const char *line);

	class DivideByZeroException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Division by zero!");
			}
		
	};
};

#endif
