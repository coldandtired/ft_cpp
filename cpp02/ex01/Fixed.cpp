/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:47:00 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/08 11:10:09 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	(*this).value = value << bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value)
{
	(*this).value = roundf(value * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
}

/*
	Assigns this Fixed to other
*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
	Overloads = so one Fixed can be assigned to another
*/
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const
{
	float	f;
	
	f = (float)(value) / (1 << bits);
	return (f);
}

int Fixed::toInt(void) const
{
	return (value >> bits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	return (stream << fixed.toFloat());
}
