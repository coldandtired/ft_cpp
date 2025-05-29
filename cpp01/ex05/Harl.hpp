/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:04:27 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/05 10:56:53 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		void 			debug(void);
		void 			info(void);
		void 			warning(void);
		void 			error(void);
	public:
		Harl();
		void complain(std::string level);
};

#endif
