/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:38:08 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/02 18:39:49 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <iomanip>
# include <cmath>

# define EPSILON 0.00001

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		enum convertType
		{
			CHAR,
			DOUBLE,
			FLOAT,
			INT,
			SPECIAL,
			UNKNOWN	
		};
		static bool isChar(const std::string &input);
		static bool isDouble(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isSpecial(const std::string &input);
		static void convertChar(const std::string &input);
		static void convertDouble(const std::string &input);
		static void convertFloat(const std::string &input);
		static void convertInt(const std::string &input);
		static void convertSpecial(const std::string &input);
		static convertType getType(const std::string &input);	
	public:
		static void convert(const std::string &input);
};

#endif
