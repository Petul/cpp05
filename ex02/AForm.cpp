/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:59:06 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 20:46:09 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

AForm::AForm() : AForm("Default form", 150, 150)
{
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute)
    : name_{name},
      grade_to_sign_{grade_to_sign},
      grade_to_execute_(grade_to_execute),
      signed_{0}
{
	if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& o)
    : name_{o.name_},
      grade_to_sign_{o.grade_to_sign_},
      grade_to_execute_(o.grade_to_execute_),
      signed_{o.signed_}
{
	if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm& AForm::operator=(const AForm& o)
{
	if (this == &o)
	{
		return (*this);
	}
	this->signed_ = o.signed_;
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (this->name_);
}

int AForm::getGradeToSign() const
{
	return (this->grade_to_sign_);
}

int AForm::getGradeToExecute() const
{
	return (this->grade_to_execute_);
}

bool AForm::getSigned() const
{
	return (this->signed_);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->grade_to_sign_)
	{
		throw GradeTooLowException();
	}
	this->signed_ = true;
}

void AForm::CheckIfExecutionPossible(Bureaucrat const& executor) const
{
	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("Error: Grade is too high");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("Error: Grade is too low");
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return ("Error: Form is not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << "Form name: " << f.getName()
	    << "\nGrade to sign: " << f.getGradeToSign()
	    << "\nGrade to execute: " << f.getGradeToExecute()
	    << "\nIs signed: " << f.getSigned();
	return (out);
}
