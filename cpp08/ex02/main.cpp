/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:30 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/05 11:00:57 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "	Inherited functions" << std::endl;
	{
		MutantStack<int> stack;

		std::cout << "Empty: " << (stack.empty() ? "yes" : "no") << std::endl;
		std::cout << "Size: " << stack.size() << std::endl;
		stack.push(5);
		stack.push(4);
		std::cout << "Size: " << stack.size() << std::endl;
		std::cout << "Top: " << stack.top() << std::endl;
		stack.pop();
		std::cout << "Size: " << stack.size() << std::endl;
		std::cout << "Top: " << stack.top() << std::endl;
	}

	std::cout << "	Subject tests: MutantStack" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(7);
		mstack.push(737);
		mstack.push(0);
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "top: " << mstack.top() << std::endl;
		std::cout << "begin: " << *mstack.begin() << std::endl;
		std::cout << "end: " << *--mstack.end() << std::endl;
	}

	std::cout << "	Subject tests: real stack" << std::endl;
	{
		std::stack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(7);
		mstack.push(737);
		mstack.push(0);
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "top: " << mstack.top() << std::endl;
	}	

	std::cout << "	Subject tests: list" << std::endl;
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		mlist.pop_back();
		mlist.push_back(7);
		mlist.push_back(737);
		mlist.push_back(0);
		std::cout << "size: " << mlist.size() << std::endl;
		std::cout << "top: " << mlist.back() << std::endl;
		std::cout << "begin: " << *mlist.begin() << std::endl;
		std::cout << "end: " << *--mlist.end() << std::endl;
	}
}
