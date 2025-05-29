/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:52:51 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/03 10:09:12 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data 		data;
	Data 		*otherData;
	uintptr_t	ptr;

	data.name = "Ed";
	data.surname = "Eddy";
	data.age = 40;

	ptr = Serializer::serialize(&data);
	otherData = Serializer::deserialize(ptr);
	std::cout << otherData->name << " " << otherData->surname << ", " << otherData->age << std::endl;
}
