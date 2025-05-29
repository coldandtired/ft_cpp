/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:11:35 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 10:19:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter
{
	private:
		static const int MAX_MATERIAS = 4;
		const std::string 	name;
		AMateria 		*materias[MAX_MATERIAS];
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);		
		Character &operator=(const Character &other);
		~Character();
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
