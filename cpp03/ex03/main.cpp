/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:39 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/10 17:02:42 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dt("Ed");
	DiamondTrap *dt2 = new DiamondTrap("DT2");
	dt.whoAmI();
	dt.guardGate();
	dt.highFivesGuys();
	dt.attack("Eddy");
	dt2->whoAmI();
	dt2->guardGate();
	dt2->highFivesGuys();
	dt2->attack("Eddy");
	delete(dt2);
}
