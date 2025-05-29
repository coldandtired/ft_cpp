/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:11:21 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/06 14:42:13 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

static	std::string	replace(std::string orig, std::string s1, std::string s2)
{
	int pos;
	int	start = 0;
	
	while (1)
	{	
		pos = orig.find(s1, start);
		if (pos > -1)
		{
			orig.erase(pos, s1.size());
			orig.insert(pos, s2);
			start = pos + s2.length();
		}
		else break;
	}
	return (orig);
}

int	main(int argc, char *argv[])
{
	std::ifstream 	inputFile;
	std::ofstream 	outputFile;
	std::string		str;
	std::string		outputFilename;
	
	if (4 != argc)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (1);
	}
		
	if (std::string(argv[2]).empty())
	{
		std::cout << "Empty search string!" << std::endl;
		return (1);
	}
		
	inputFile.open(argv[1]);
	if (inputFile.fail())
	{
		std::cout << "Can't open input file!" << std::endl;
		return (1);
	}

	outputFilename = std::string(argv[1]).append(".replace");
	outputFile.open(outputFilename.c_str());
	
	if (outputFile.fail())
	{
		std::cout << "Can't open output file!" << std::endl;
		return (1);
	}
		
	while (getline(inputFile, str))
	{
		str = replace(str, argv[2], argv[3]);
		outputFile << str << std::endl;
	}
}
