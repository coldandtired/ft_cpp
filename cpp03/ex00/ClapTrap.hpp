/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:17:54 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 11:59:06 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			damage;
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &other);
		ClapTrap &operator=(ClapTrap &other);		
		~ClapTrap();
		std::string	getName(void);
		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
};

#endif

