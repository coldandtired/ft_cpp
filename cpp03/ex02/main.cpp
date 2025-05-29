/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/10 16:53:02 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap ct("Ed");
	ScavTrap sc("Eddy");
	FragTrap ft("Edward");
	ClapTrap *ft2 = new FragTrap("FT2");
	sc.guardGate();
	sc.attack(ct.getName());
	ct.takeDamage(20);
	sc.beRepaired(3);
	ft.highFivesGuys();
	delete(ft2);
}
