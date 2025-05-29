/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:40 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 11:27:09 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>
# include <string>
# include <iostream>

template<typename T, typename C = std::list<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack &operator=(MutantStack const &other);
		~MutantStack();

		typedef typename C::iterator iterator;
	
		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"

#endif
