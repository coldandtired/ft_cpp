/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:50 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 11:23:01 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>() {}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(MutantStack const &other)
{
	*this = other;
}

template<typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(MutantStack const &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
	return this->c.begin();
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
	return this->c.end();
}

#endif
