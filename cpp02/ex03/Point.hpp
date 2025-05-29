/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:35:16 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:44:54 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(Point &other);
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
