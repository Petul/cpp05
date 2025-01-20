/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:06:09 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 09:32:12 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat joe("Joe", 1);
		Intern sam;

		AForm* ppf = sam.makeForm("presidential pardon", "Bob");

		joe.signForm(*ppf);
		joe.executeForm(*ppf);

		delete ppf;
	}

	{
		Bureaucrat joe("Joe", 1);
		Intern sam;

		AForm* rrf = sam.makeForm("robotomy request", "Bob");

		joe.signForm(*rrf);
		joe.executeForm(*rrf);

		delete rrf;
	}

	{
		Bureaucrat joe("Joe", 1);
		Intern sam;

		AForm* scf = sam.makeForm("shrubbery creation", "Bob");

		joe.signForm(*scf);
		joe.executeForm(*scf);

		delete scf;
	}

	{
		Bureaucrat joe("Joe", 1);
		Intern sam;

		AForm* scf = sam.makeForm("sleeping permit", "Bob");
		(void)scf;
	}
}
