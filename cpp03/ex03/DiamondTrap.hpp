/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:46:26 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:51:26 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
		using FragTrap::hitPoints;
		using ScavTrap::energyPoints;
		using FragTrap::damage;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &other);
		DiamondTrap &operator=(DiamondTrap &other);
		~DiamondTrap();
		void	attack(const std::string& target);
		void 	whoAmI();
};

#endif
