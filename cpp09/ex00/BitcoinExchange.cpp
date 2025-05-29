/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:35:02 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/04 15:11:39 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

ExchangeRates::ExchangeRates() {}

ExchangeRates::ExchangeRates(const ExchangeRates &other)
{
	*this = other;
}

ExchangeRates &ExchangeRates::operator=(const ExchangeRates &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

ExchangeRates::~ExchangeRates() {}

bool ExchangeRates::readDB(const char *fileName)
{
	std::string line;
	std::ifstream dbFile;
	std::string date;
	float value;
	
	dbFile.open(fileName);
	if (!dbFile)
	{
		std::cerr << "Can't open input file!" << std::endl;
		return false;
	}
	while (getline (dbFile, line))
	{
		if ("date,exchange_rate" == line)
			continue;
		date = line.substr(0, 10);
		value = atof(line.substr(11).c_str());
		values[date] = value;
	}
  	dbFile.close();
	return true;
}

float ExchangeRates::getValue(std::string date)
{
	std::map<std::string, float>::iterator it = values.find(date);
	if (it == values.end())
	{
		struct tm tm;
		strptime(date.c_str(), "%Y-%m-%d", &tm);
		struct tm tm2;
		
		for(std::map<std::string, float>::reverse_iterator start = values.rbegin(); 
        start != values.rend();
        start++)
		{
			strptime(start->first.c_str(), "%Y-%m-%d", &tm2);
			if (tm2.tm_year > tm.tm_year)		
				continue;
			if ((tm2.tm_yday > tm.tm_yday))
				continue;
			return start->second;
		}
		return -1;
	}
	return it->second;
}

bool ExchangeRates::readInputFile(const char *fileName)
{
	std::string line;
	std::ifstream inputFile;
	std::string date;
	float value;
	struct tm tm;
	float foundValue;
	
	inputFile.open(fileName);
	if (!inputFile)
	{
		std::cerr << "Can't open input file!" << std::endl;
		return false;
	}
	while (getline (inputFile, line))
	{		
		if ("date | value" == line)
			continue;
		if (line.size() < 11)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, 10);
		value = atof(line.substr(12).c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if (NULL == strptime(date.c_str(), "%Y-%m-%d", &tm))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		foundValue = getValue(date);
		std::cout << date << " => " << value << " => " << (foundValue * value) << std::endl;
	}
	inputFile.close();
	return true;
}
