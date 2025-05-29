/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:37:55 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 10:11:16 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(const std::string &input)
{	
	size_t len = input.length();
	
	if (3 == len && '\'' == input.at(0) && '\'' == input.at(2))
		return true;
	if (1 == len && (input.c_str()[0] >= 32 && input.c_str()[0] <= 126))
		return true;
	return false;
}

bool ScalarConverter::isDouble(const std::string &input)
{	
	size_t len = input.length();
	
	if (input.find_first_of(".") != std::string::npos && 'f' != input.at(len - 1))
		return true;
		
	return false;
}

bool ScalarConverter::isFloat(const std::string &input)
{	
	size_t len = input.length();
	std::stringstream 	sstream;
	double	num;
	
	if (input.find_first_of(".") != std::string::npos && 'f' == input.at(len - 1))
	{		
		sstream << input;
		sstream >> num;
		if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
		{
			std::cout << num << " " << std::numeric_limits<float>::min() <<std::endl;
			return false;
		}
		else
			return true;
	}
		
	return false;
}

bool ScalarConverter::isInt(const std::string &input)
{
	std::stringstream 	sstream;
	int					num;
	std::string			text;
	
	sstream << input;
	sstream >> num;
	sstream.clear();
	sstream << num;
	sstream >> text;
	if (text == input)
		return true;
	return false;
}

bool ScalarConverter::isSpecial(const std::string &input)
{
	std::string specials[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	
	for (int i = 0; i < 6; i++)
		if (specials[i] == input)
			return true;
	return false;
}

void ScalarConverter::convertChar(const std::string &input)
{
	char	num;
	size_t	len;

	len = input.length();
	if (1 == len)
		num = input.c_str()[0];
	else
		num = input.c_str()[2];
	std::cout << "char: " << "'" << num << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input)
{
	std::stringstream 	sstream;
	double				num;
	
	sstream << input;
	sstream >> num;

	if (num < 32 || 127 == num)
		std::cout << "char: Non displayable" << std::endl;
	else if (num > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
		
	if (int(num) > std::numeric_limits<int>::max() || int(num) < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (num - EPSILON > std::numeric_limits<float>::max() || num + EPSILON < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(num) << "f" << std::endl;
		
	std::cout << "double: " << num << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input)
{
	std::stringstream 	sstream;
	float				num;
	
	sstream << input;
	sstream >> num;

	if (num < 32 || 127 == num)
		std::cout << "char: Non displayable" << std::endl;
	else if (num > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
		
	if (floor(num) > std::numeric_limits<int>::max() || floor(num) < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		
	std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
	std::stringstream 	sstream;
	int					num;
	
	sstream << input;
	sstream >> num;

	if (num < 32 || 127 == num)
		std::cout << "char: Non displayable" << std::endl;
	else if (num > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::convertSpecial(const std::string &input)
{
	std::stringstream 	sstream;
	int					num;
	
	sstream << input;
	sstream >> num;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if ("-inf" == input || "-inff" == input)
	{
		std::cout << "int: -inf" << std::endl;
		std::cout << "float: -inff" << std::endl;
	}
	if ("+inf" == input || "+inff" == input)
	{
		std::cout << "int: +inf" << std::endl;
		std::cout << "float: +inff" << std::endl;		
	}
	if ("nan" == input || "nanf" == input)
	{
		std::cout << "int: nan" << std::endl;
		std::cout << "float: nanf" << std::endl;		
	}
}

ScalarConverter::convertType ScalarConverter::getType(const std::string &input)
{
	if (isSpecial(input))
		return SPECIAL;
	if (isDouble(input))
		return DOUBLE;
	if (isFloat(input))
		return FLOAT;
	if (isInt(input))
		return INT;
	if (isChar(input))
		return CHAR;

	return UNKNOWN;
}

void ScalarConverter::convert(const std::string &input)
{
	convertType type = getType(input);
	
	switch (type)
	{
		case CHAR:
			convertChar(input);
			break;
		case DOUBLE:
			convertDouble(input);
			break;
		case FLOAT:
			convertFloat(input);
			break;
		case INT:
			convertInt(input);
			break;
		case SPECIAL:
			convertSpecial(input);
			break;
		default:
			std::cout << "Unknown type!" << std::endl;		
	}
}
