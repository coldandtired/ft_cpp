/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:49:29 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/05 10:58:13 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	srand(time(0));
	
	std::cout << "	Exceptions" << std::endl;
	{
		Span span;

		try
		{
			span.addNumber(7);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{	
			std::vector<int> tmp;
			for (int i = 0; i < 100; i++)
				tmp.push_back(rand() % 10000);
			span.addNumbers(tmp.begin(), tmp.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "	Small test" << std::endl;	
	{
		Span span = Span(5);
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}

	std::cout << "	100 test" << std::endl;
	{	
		Span span(100);
		std::vector<int> tmp;
		for (int i = 0; i < 100; i++)
			tmp.push_back(rand() % 1000000);
		span.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}

	std::cout << "	100,000 test" << std::endl;
	{	
		Span span(100000);
		std::vector<int> tmp;
		for (int i = 0; i < 10000; i++)
			tmp.push_back(rand() % 100000000);
		span.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	
	return 0;
}
