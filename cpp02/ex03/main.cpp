/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:46:57 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 11:14:05 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main( void )
{
	Point P1;
	Point P2(4.18f, 3.02f);
	Point P3(P2);
	Point P4(94.16f, 100.12f);
	Point P5(2.56f, 2.08f);
	Point P(1.5f, 1.5f); 
	Point P6 = P;
	Point P7(-0.5f, -0.5f);
	
	Point Tc(0, 0);
	Point Ta(5.12, 4.16);
	Point Tb(1.18, -6.49);

	Point Tx(0, 3.02);
	Point Ty(5, 3.02);
	Point Tz(2.5, 0);

	std::cout << "P1: edge: " << bsp(Ta, Tb, Tc, P1) << std::endl;
	std::cout << "P2: inside: " << bsp(Ta, Tb, Tc, P2) << std::endl;
	std::cout << "P3: edge: " << bsp(Tx, Ty, Tz, P3) << std::endl;
	std::cout << "P4: outside: " << bsp(Ta, Tb, Tc, P4) << std::endl;
	std::cout << "P5: edge: " << bsp(Ta, Tb, Tc, P5) << std::endl;
	std::cout << "P6: inside: " << bsp(Tx, Ty, Tz, P6) << std::endl;
	std::cout << "P7: outside: " << bsp(Tx, Ty, Tz, P7) << std::endl;
	return 0; 
}
