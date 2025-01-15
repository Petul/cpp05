/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:06:09 by pleander          #+#    #+#             */
/*   Updated: 2025/01/15 21:40:05 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat foo("Joe", 1);

		std::cout << foo << std::endl;
		try
		{
			foo.increment_grade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << foo << std::endl;
	}
	{
		Bureaucrat foo("Mark", 150);

		std::cout << foo << std::endl;
		try
		{
			foo.increment_grade();
			foo.decrement_grade();
			foo.decrement_grade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << foo << std::endl;
	}
}
