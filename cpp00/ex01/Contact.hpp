/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:56:37 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 15:15:33 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		void		format(std::string member);
	public:
		void		setFirstName(std::string);
		void		setLastName(std::string);
		void		setNickName(std::string);
		void		setPhoneNumber(std::string);
		void		setDarkestSecret(std::string);
		bool		empty(void);
		void		displaySingle(void);
		void		displayLine(int index);
};

#endif
