/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:50:17 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 15:36:53 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool PhoneBook::isNumber(std::string str)
{
    std::stringstream 	stream;                   
	double				number;

	stream << str;
	stream >> number;
	return stream.eof();
}

std::string	PhoneBook::trim(std::string input)
{
	while(0 == input.compare(0, 1, " ") || 0 == input.compare(0, 1, "\t"))
		input.erase(input.begin());
	while(input.size() > 0 && (0 == input.compare(input.size() -1, 1, " ")
		|| 0 == input.compare(input.size() -1, 1, "\t")))
		input.erase(input.end() -1);
	return (input);
}

void	PhoneBook::add(void)
{
	Contact		contact;
	int			i;
	std::string	result;

	std::cout << "Please enter the details for a new contact:\n" << std::flush;
	
	while (1)
	{
		std::cout << "First name     : " << std::flush;
		std::getline(std::cin, result);
		if (std::cin.eof() || result.empty() || result.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			continue ;
		contact.setFirstName(trim(result));
		break;
	}
	
	while (1)
	{
		std::cout << "Last name      : " << std::flush;
		std::getline(std::cin, result);
		if (std::cin.eof() || result.empty() || result.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			continue ;
		contact.setLastName(trim(result));
		break;
	}
	
	while (1)
	{
		std::cout << "Nickname       : " << std::flush;
		std::getline(std::cin, result);
		if (std::cin.eof() || result.empty() || result.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			continue ;
		contact.setNickName(trim(result));
		break;
	}
	
	while (1)
	{
		std::cout << "Phone number   : " << std::flush;
		std::getline(std::cin, result);
		if (std::cin.eof())
			return;
		if (result.empty() || !isNumber(result) || result.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			continue;
		contact.setPhoneNumber(trim(result));
		break;
	}
	
	while (1)
	{
		std::cout << "Darkest secret : " << std::flush;
		std::getline(std::cin, result);
		if (std::cin.eof() || result.empty() || result.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			continue ;
		contact.setDarkestSecret(trim(result));
		break;
	}
	
	i = 0;
	while (i < 8)
	{
		if (contacts[i].empty())
			break;
		i++;
	}
	if (8 == i)
		i = 0;
	contacts[i] = contact;
}

int	PhoneBook::validateChoice(std::string choice)
{
	int	count;
	
	if (choice.size() != 1)
		return (-1);
	if (!isdigit(choice[0]))
		return (-1);
	std::istringstream(choice) >> count;
	if (count < 0 || count > 7)
		return (-1);
	return (count);
}

void	PhoneBook::search(void)
{	
	Contact 	contact;
	int			i;
	int			count;
	std::string	choice;

	i = 0;
	count = 0;
	while (i < 8)
	{
		if (!contacts[i].empty())
			count++;
		i++;
	}
	if (0 == count)
	{
		std::cout << "No contacts!" << std::endl;
		return ;
	}
	
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	i = 0;
	while (i < 8)
	{
		if (!contacts[i].empty())
			contacts[i].displayLine(i);
		i++;
	}

	std::cout << "Which would you like to see? " << std::flush;
	std::getline(std::cin, choice);
	if (std::cin.eof())
		return;
	if (!choice.empty() )
	{
		count = validateChoice(choice);
		if (-1 == count || contacts[count].empty())
		{
			std::cout << "Bad index!" << std::endl;
			return ;
		}
		else
		{
			contacts[count].displaySingle();
			return ;
		}
	}
}
