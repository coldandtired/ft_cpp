/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:37:08 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 11:11:25 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"

Fixed	calcW1(Point a, Point b, Point c, Point p)
{
	Fixed c1 = a.getX() *  (c.getY() - a.getY());
	Fixed c2 = p.getY() - a.getY();
	Fixed c3 = c.getX() - a.getX();
	Fixed c4 = p.getX() * (c.getY() - a.getY());

	Fixed c5 = b.getY() - a.getY();
	Fixed c6 = c.getX() - a.getX();
	Fixed c7 = b.getX() - a.getX();
	Fixed c8 = c.getY() - a.getY();

	Fixed top = c1 + (c2 * c3) - c4;
	Fixed bottom = (c5 * c6) - (c7 * c8);
	
	return (top / bottom);
}

Fixed	calcW2(Fixed w1, Point a, Point b, Point c, Point p)
{
	Fixed c1 = p.getY() - a.getY();
	Fixed c2 = w1 * (b.getY() - a.getY());
	
	Fixed top = c1 - c2;
	Fixed bottom = c.getY() - a.getY();

	return (top / bottom);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1 = calcW1(a, b, c, point);
	Fixed	w2 = calcW2(w1, a, b, c, point);

	return (w1 > 0 && w2 > 0 && (w1 + w2) < 1);
}
