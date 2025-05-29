/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:36:55 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:40:39 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
    	~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
