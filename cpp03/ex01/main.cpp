/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/10 16:39:27 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap ct("Ed");
	ScavTrap ct2("Eddy");
	ClapTrap *cc = new ScavTrap("SC");

	cc->attack("Test");
	ct2.guardGate();
	ct2.attack(ct.getName());
	ct.takeDamage(20);
	ct2.beRepaired(3);
	delete(cc);
}
