/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:52:30 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 11:06:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T, typename U>
void iter(T *array, size_t len, U function)
{
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

#endif
