/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:45:38 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 15:15:40 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string name)
{
	firstName = name;
}

void	Contact::setLastName(std::string name)
{
	lastName = name;
}

void	Contact::setNickName(std::string name)
{
	nickName = name;
}

void	Contact::setPhoneNumber(std::string number)
{
	phoneNumber = number;
}

void	Contact::setDarkestSecret(std::string secret)
{
	darkestSecret = secret;
}

void	Contact::format(std::string member)
{
	int	len;

	len = member.size();
	if (len < 10)
		std::cout << std::setw(10) << member << "|" << std::flush;
	else
		std::cout << member.substr(0, 9) << ".|" << std::flush;
}

void	Contact::displayLine(int index)
{
	std::stringstream	convert;

	convert << index;
	format(convert.str());
	format(firstName);
	format(lastName);
	format(nickName);
	std::cout << std::endl;
}

void	Contact::displaySingle(void)
{
	std::cout << "First name    : " << firstName << std::endl;
	std::cout << "Last name     : " << lastName << std::endl;
	std::cout << "Nick name     : " << nickName << std::endl;
	std::cout << "Phone number  : " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

bool	Contact::empty()
{
	return (firstName.empty());
}
