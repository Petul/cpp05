/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:35:01 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 21:05:40 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : ShrubberyCreationForm("Default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target_{target}
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
    : ShrubberyCreationForm(o.target_)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& o)
{
	if (this == &o)
	{
		return (*this);
	}
	this->target_ = o.target_;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	CheckIfExecutionPossible(executor);
	std::ofstream of{this->target_ + "_shrubbery"};
	for (int i = 0; i < 5; i++)
	{
		of << "    #    \n"
		   << "   ###   \n"
		   << "  #####  \n"
		   << " ####### \n"
		   << "    H    \n\n";
	}
	of << std::endl;
	of.close();
}
