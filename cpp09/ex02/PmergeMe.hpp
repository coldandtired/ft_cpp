/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:52:13 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/07 11:07:50 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <deque>
# include <vector>
# include <iterator>
# include <cmath>
# include <ctime>

typedef struct s_listpair
{
	char			side;
	int				pairNumber;
	std::list<int> 	numbers;
}	t_listpair;

class ListSorter
{
	private:
		ListSorter();
		size_t	count;
		size_t	groupSize;
		std::list<int> numbers;
		int JSNumber(int previous);
		void fillPairs(std::list<t_listpair> &pairs);
		void fillNums(std::list<t_listpair> &pairs);
		void swapPairs(std::list<t_listpair> &pairs);
		void addLabels(std::list<t_listpair> &pairs);
		std::list<t_listpair>::iterator mainPos(std::list<t_listpair> &pairs, int num);
		void mergeNums();
		void sortNums();
	public:
		ListSorter(std::list<int> numbers);
		ListSorter(const ListSorter &other);
		ListSorter &operator=(const ListSorter &other);
		~ListSorter();
		clock_t start();
};

typedef struct s_dequepair
{
	char			side;
	int				pairNumber;
	std::deque<int>	numbers;
}	t_dequepair;

class DequeSorter
{
	private:
		DequeSorter();
		size_t	count;
		size_t	groupSize;
		std::deque<int> numbers;
		int JSNumber(int previous);
		void fillPairs(std::deque<t_dequepair> &pairs);
		void fillNums(std::deque<t_dequepair> &pairs);
		void swapPairs(std::deque<t_dequepair> &pairs);
		void addLabels(std::deque<t_dequepair> &pairs);
		std::deque<t_dequepair>::iterator mainPos(std::deque<t_dequepair> &pairs, int num);
		void mergeNums();
		void sortNums();
	public:
		DequeSorter(std::deque<int> numbers);
		DequeSorter(const DequeSorter &other);
		DequeSorter &operator=(const DequeSorter &other);
		~DequeSorter();
		clock_t start();
};

#endif
