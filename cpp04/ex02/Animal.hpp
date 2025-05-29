/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:07:44 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/12 14:17:58 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal &other);
		Animal &operator=(Animal &other);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound(void) const = 0;
};

#endif
