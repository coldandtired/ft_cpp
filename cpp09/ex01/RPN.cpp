/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:22:58 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/07 09:44:59 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Parser::Parser() : total(0) {}

Parser::Parser(const Parser &other)
{
	total = other.total;
	*this = other;
}

Parser &Parser::operator=(const Parser &other)
{
	if (this != &other)
	{
		total = other.total;
		*this = other;
	}
	return *this;
}

Parser::~Parser() {}

int Parser::calculate(int a, int b, char sign)
{
	if (0 == b && '/' == sign)
		throw DivideByZeroException();
	switch (sign)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			return a / b;
		default:
			return a * b;
	}
	return 0;
}

bool Parser::parseLine(const char *line)
{
	int	a;
	int	b;
	int result;
	
	std::string str(line);
	for(std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (' ' == *it)
			continue;
		if (isdigit(*it))
			values.push(*it - '0');
		else if ('+' == *it || '-' == *it || '/' == *it || '*' == *it)
		{
			if (values.size() < 2)
				return false;
			b = values.top();
			values.pop();
			a = values.top();
			values.pop();
			result = calculate(a, b, *it);
			values.push(result);
		}
		else
			return false;
	}
	if (1 != values.size())
		return false;
	std::cout << values.top() << std::endl;
	return true;
}
