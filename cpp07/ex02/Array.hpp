/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:14:45 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 09:14:56 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template<typename T>
class Array
{
	private:
		T		*elements;
		size_t	count;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int i);
		T &operator[](unsigned int i) const;
		~Array();
		unsigned int	size() const;
		
	class InvalidIndexException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Index too high!");
			}
	};
};

// has to be after the class
# include "Array.tpp"

#endif
