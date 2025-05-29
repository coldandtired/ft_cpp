/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:10:53 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 13:55:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>

class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found!");
		}
	
};

template<typename T>
typename T::iterator easyfind(T &container, int num)
{
	typename T::iterator item;
	
	item = std::find(container.begin(), container.end(), num);
	if (item == container.end())
		throw NotFoundExeption();
	return item;
}

#endif
