/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:58:31 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 15:37:16 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <sstream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];
		bool		isNumber(std::string);
		int			validateChoice(std::string choice);
		std::string	trim(std::string input);
	public:
		void	add(void);
		void	search(void);
};

#endif
