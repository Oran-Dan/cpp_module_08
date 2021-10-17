/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:09:06 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/17 17:36:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	ft_display_header(std::string name)
{
	std::cout << name << std::endl;
	std::cout << "----------------------------" << std::endl;
}

void	ft_displayInt(int i)
{
	std::cout << i << std::endl;
}


// List stores data with a non contiguous way (using doubly linked pointers)
// Vectors vs lists = same story as arrays vs linked lists
void	ft_list_tests(void)
{
	// Create a list containing integers
	std::list<int> lst;
	for (int i = 1; i <= 5; i++)
		lst.push_back(i);
	
	// Display each element of this list
	std::cout << std::endl;
	ft_display_header("LIST ELEMENTS");
	std::for_each(lst.begin(), lst.end(), ft_displayInt);
	std::cout << std::endl;

	// Use easyfind
	ft_display_header("EXISTING ELEMENT");
	std::cout << easyfind(lst, 2) << std::endl << std::endl; // will return the iterator to "2"
	ft_display_header("NOT EXISTING ELEMENT");
	try
	{
		std::cout << easyfind(lst, -28) << std::endl << std::endl; // will return the iterator to "3" (the last element)
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
}

// Vector = dynamic array, its size can change
// It stores data with a contiguous way (like a regular array, not a linked list)
// Data is inserted in the back
void	ft_vector_tests(void)
{
	std::vector<int> vector;

	for (int i = 1; i <= 5; i++)
		vector.push_back(i);

	// Display each element of this list
	std::cout << std::endl;
	ft_display_header("VECTOR ELEMENTS");
	std::for_each(vector.begin(), vector.end(), ft_displayInt);
	std::cout << std::endl;

	// Use easyfind
	ft_display_header("EXISTING ELEMENT");
	std::cout << easyfind(vector, 2) << std::endl << std::endl; // will return the iterator to "2"
	ft_display_header("NOT EXISTING ELEMENT");
	try
	{
		std::cout << easyfind(vector, -28) << std::endl << std::endl; // will return the iterator to "3" (the last element)
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
}

// Array = good old fixed size array from C
void	ft_array_tests(void)
{
	std::array<int, 5> array; //need to give the size directly

	for (int i = 1; i <= 5; i++)
		array[i - 1] = i;

	// Display each element of this list
	std::cout << std::endl;
	ft_display_header("ARRAY ELEMENTS");
	std::for_each(array.begin(), array.end(), ft_displayInt);
	std::cout << std::endl;

	// Use easyfind
	ft_display_header("EXISTING ELEMENT");
	std::cout << easyfind(array, 2) << std::endl << std::endl; // will return the iterator to "2"
	ft_display_header("NOT EXISTING ELEMENT");
	try
	{
		std::cout << easyfind(array, -28) << std::endl << std::endl; // will return the iterator to "3" (the last element)
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
}

int main(void)
{
	ft_list_tests();
	ft_vector_tests();
	ft_array_tests();
	return (0);
}