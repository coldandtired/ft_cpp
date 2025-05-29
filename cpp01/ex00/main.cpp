/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:36:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:39:40 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Stack:" << std::endl;
	Zombie	zombie1("Ed");
	zombie1.announce();

	std::cout << "Heap:" << std::endl;
	Zombie	*zombie2 = newZombie("Eddy");
	zombie2->announce();
	delete(zombie2);	

	std::cout << "Stack:" << std::endl;
	randomChump("Edward");
}
