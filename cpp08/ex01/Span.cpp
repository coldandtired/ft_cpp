/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:58:05 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/05 10:58:06 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_numbers(0) {}

Span::Span(unsigned int max_numbers) : max_numbers(max_numbers) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		max_numbers = other.max_numbers;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (numbers.size() == max_numbers)
		throw FullNumbersException();
	numbers.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to)
{
	int distance = std::distance(from, to);
	if (numbers.size() + distance > max_numbers)
		throw FullNumbersException();
	numbers.insert(numbers.end(), from, to);
}

unsigned int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw NoSpanException();
	std::sort(numbers.begin(), numbers.end());
	int	span = longestSpan();
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end() - 1; it++)
	{
		if (*(it + 1) - *it < span)
			span = *(it + 1) - *it;
	}
	return span;
}

unsigned int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw NoSpanException();
	std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
	return *max - *min;
}
