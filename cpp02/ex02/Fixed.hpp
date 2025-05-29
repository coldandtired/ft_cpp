/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:47:04 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/05 18:33:22 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int operator>(const Fixed &other) const;
		int operator<(const Fixed &other) const;
		int operator>=(const Fixed &other) const;
		int operator<=(const Fixed &other) const;
		int operator==(const Fixed &other) const;
		int operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &stream, Fixed const &fixed);

#endif
