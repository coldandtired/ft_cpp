/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:48:33 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 09:15:01 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), count(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), count(n) {}

template<typename T>
Array<T>::Array(const Array &other) : elements(new T[other.size()]), count(other.size())
{
	for (size_t i = 0; i < count; i++)
		elements[i] = other.elements[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != other)
	{
		delete[] elements;
		count = other.size();
		elements = new T[count];
		for (size_t i = 0; i < count; i++)
			elements[i] = other.elements[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= count)
		throw InvalidIndexException();
	return elements[i];
}

template<typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= count)
		throw InvalidIndexException();
	return elements[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return count;
}

#endif
