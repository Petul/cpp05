/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:34:12 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 21:35:57 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : PresidentialPardonForm("Default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target_{target}
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
    : PresidentialPardonForm(o.target_)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& o)
{
	if (this == &o)
	{
		return (*this);
	}
	this->target_ = o.target_;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	check_if_execution_possible(executor);
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox."
	          << std::endl;
}
