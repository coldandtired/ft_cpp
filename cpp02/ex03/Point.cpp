/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:35:12 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 11:10:07 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(Fixed(0.0f)), y(Fixed(0.0f)){}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)){}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()){}

Point &Point::operator=(Point &other)
{
	return (other);
}

Point::~Point(){}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
