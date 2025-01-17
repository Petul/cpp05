/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:34:47 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 09:26:23 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern&)
{
}
Intern& Intern::operator=(const Intern&)
{
	return (*this);
}
Intern::~Intern()
{
}

AForm* Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* (Intern::* forms[])(std::string){
	    &Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
	    &Intern::makePresidentialPardonForm};

	std::string form_names[]{"shrubbery creation", "robotomy request",
	                         "presidential pardon"};
	AForm* new_form;
	for (int i = 0;
	     i < (int)(sizeof(forms) / sizeof(AForm * (Intern::*)(std::string)));
	     i++)
	{
		if (form_names[i] == name)
		{
			try
			{
				new_form = ((this->*forms[i])(target));
				std::cout << "Intern creates " << name << "." << std::endl;
				return new_form;
			}
			catch (std::bad_alloc& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	std::cout << "The form " << name << " does not exist." << std::endl;
	return (nullptr);
}
