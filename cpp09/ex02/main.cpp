/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:52:46 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/07 10:58:48 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (1 == argc)
	{
		std::cout << "Bad arguments!" << std::endl;
		return 1;
	}
	
	std::list<int> listNums;
	int num;
	int	i = 0;
	while (argv[++i])
	{
		num = atoi(argv[i]);
		if (num < 0)
		{
			std::cout << "Negative number!" << std::endl;
			return 1;
		}
		listNums.push_back(num);
	}

	std::deque<int> dequeNums;
	i = 0;
	while (argv[++i])
		dequeNums.push_back(atoi(argv[i]));

	std::cout << "Before: ";
	for (std::list<int>::iterator it = listNums.begin(); it != listNums.end(); it++)
		std::cout << *it << " "; 
	std::cout << std::endl;

	ListSorter listSorter(listNums);
	std::clock_t time = listSorter.start();
	std::cout << "Time to process a range of " << listNums.size() << " elements with std::list : " << time << " milliseconds" <<std::endl;

	DequeSorter dequeSorter(dequeNums);
	time = dequeSorter.start();
	std::cout << "Time to process a range of " << dequeNums.size() << " elements with std::deque : " << time << " milliseconds" <<std::endl;
}
