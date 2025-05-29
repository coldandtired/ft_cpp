/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:42:13 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:40:45 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int	i;
	Zombie	*horde = new Zombie[N];
	i = -1;
	while (++i < N)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}
