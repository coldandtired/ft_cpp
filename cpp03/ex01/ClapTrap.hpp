/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:17:54 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/10 16:38:12 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &other);
		ClapTrap &operator=(ClapTrap &other);
		virtual ~ClapTrap();
		std::string		getName(void);
		virtual void 	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void 	beRepaired(unsigned int amount);
};

#endif

