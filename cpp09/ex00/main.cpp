/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:34:56 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 15:10:46 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (2 != argc)
	{
		std::cerr  << "Missing argument!" << std::endl;
		return 1;
	}
	
	ExchangeRates rates;
	if (rates.readDB("data.csv"))
		rates.readInputFile(argv[1]);
  
	return 0;
}
