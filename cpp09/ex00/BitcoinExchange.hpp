/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:35:09 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 15:10:03 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdlib>
# include <string>
# include <ctime>
# include <fstream>

class ExchangeRates
{
	private:
		float getValue(std::string date);
		std::map<std::string, float> values;
	public:
		ExchangeRates();
		ExchangeRates(const ExchangeRates &other);
		ExchangeRates &operator=(const ExchangeRates &other);
		~ExchangeRates();
		bool readDB(const char *fileName);
		bool readInputFile(const char *fileName);
};

#endif
