/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:06:09 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 13:38:55 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Form sleeping_permit("Sleeping permit", 0, 10);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form sleeping_permit("Sleeping permit", 150, 10);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form sleeping_permit("Sleeping permit", 100, 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form sleeping_permit("Sleeping permit", 100, 150);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form default_form;
			std::cout << default_form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		Bureaucrat foo("Joe", 1);

		Form sleeping_permit("Sleeping permit", 100, 10);
		std::cout << sleeping_permit << std::endl;
		foo.sign_form(sleeping_permit);
		std::cout << sleeping_permit << std::endl;
	}

	{
		Bureaucrat foo("Mike", 50);

		Form sleeping_permit("Sleeping permit", 50, 10);
		std::cout << sleeping_permit << std::endl;
		foo.sign_form(sleeping_permit);
		std::cout << sleeping_permit << std::endl;
	}
	{
		Bureaucrat foo("Jason", 51);

		Form sleeping_permit("Sleeping permit", 50, 10);
		std::cout << sleeping_permit << std::endl;
		foo.sign_form(sleeping_permit);
		std::cout << sleeping_permit << std::endl;
	}
}
