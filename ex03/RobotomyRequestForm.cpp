/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:14:46 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 21:31:50 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : RobotomyRequestForm("Default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target_{target}
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
    : RobotomyRequestForm(o.target_)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& o)
{
	if (this == &o)
	{
		return (*this);
	}
	this->target_ = o.target_;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	check_if_execution_possible(executor);
	std::cout << "*** Drilling noises ***\n";
	srand(time(0));
	if (std::rand() % 2)
	{
		std::cout << this->target_ << " has been robotomized successfully.";
	}
	else
	{
		std::cout << "Robotomy of target " << this->target_ << " failed.";
	}
	std::cout << std::endl;
}
