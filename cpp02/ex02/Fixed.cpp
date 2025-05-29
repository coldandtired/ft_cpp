/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:47:00 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:44:20 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(int value)
{
	(*this).value = value << bits;
}

Fixed::Fixed(float value)
{
	(*this).value = roundf(value * (1 << bits));
}

/*
	Assigns this Fixed to other
*/
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

/*
	Overloads = so one Fixed can be assigned to another
*/
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		value = other.value;
	return (*this);
}

int Fixed::operator<(const Fixed &other) const
{
	return (value < other.value);
}

int Fixed::operator>(const Fixed &other) const
{
	return (value > other.value);
}

int Fixed::operator<=(const Fixed &other) const
{
	return (value <= other.value);
}

int Fixed::operator>=(const Fixed &other) const
{
	return (value >= other.value);
}

int Fixed::operator==(const Fixed &other) const
{
	return (value == other.value);
}

int Fixed::operator!=(const Fixed &other) const
{
	return (value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	value++;
	return (*this);
}

Fixed &Fixed::operator--()
{	
	value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	pre = *this;
	value++;
	return (pre);
}

Fixed Fixed::operator--(int)
{	
	Fixed	pre = *this;
	value--;
	return (pre);
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(const int raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (((float)value) / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (value >> bits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	return (stream << fixed.toFloat());
}
