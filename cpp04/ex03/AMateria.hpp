/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:36:45 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/13 14:15:36 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		const std::string 	type;
		bool				isEquipped;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		std::string const &getType() const;
		bool getEquipped(void);
		void setEquipped(bool equip);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
