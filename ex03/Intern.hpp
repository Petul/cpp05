/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:34:44 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 08:54:33 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
   public:
	Intern();
	Intern(const Intern &);
	Intern &operator=(const Intern &);
	~Intern();

	AForm *makeForm(std::string name, std::string target);

   private:
	AForm *makeShrubberyCreationForm(std::string target);
	AForm *makeRobotomyRequestForm(std::string target);
	AForm *makePresidentialPardonForm(std::string target);
};

#endif
