/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:06:09 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 21:37:30 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		Bureaucrat joe("Joe", 1);

		ShrubberyCreationForm f("home");
		joe.signForm(f);
		joe.executeForm(f);
	}

	{
		Bureaucrat sam("Sam", 146);

		ShrubberyCreationForm f("home");
		sam.signForm(f);
		sam.executeForm(f);
	}

	{
		Bureaucrat bob("Bob", 138);

		ShrubberyCreationForm f("home");
		bob.signForm(f);
		bob.executeForm(f);
	}
	{
		Bureaucrat foo("Foo", 40);

		RobotomyRequestForm f("Joe");
		foo.signForm(f);
		foo.executeForm(f);
	}
	{
		Bureaucrat mark("Mark", 1);

		PresidentialPardonForm f("Bob");
		mark.signForm(f);
		mark.executeForm(f);
	}
}
