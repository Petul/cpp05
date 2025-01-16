/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:59:06 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 13:35:06 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

Form::Form() : Form("Default form", 150, 150)
{
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
    : name_{name},
      grade_to_sign_{grade_to_sign},
      grade_to_execute_(grade_to_execute),
      signed_{0}
{
	if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& o)
    : name_{o.name_},
      grade_to_sign_{o.grade_to_sign_},
      grade_to_execute_(o.grade_to_execute_),
      signed_{o.signed_}
{
	if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form& Form::operator=(const Form& o)
{
	if (this == &o)
	{
		return (*this);
	}
	this->signed_ = o.signed_;
	return (*this);
}

Form::~Form()
{
}

std::string Form::get_name() const
{
	return (this->name_);
}

int Form::get_grade_to_sign() const
{
	return (this->grade_to_sign_);
}

int Form::get_grade_to_execute() const
{
	return (this->grade_to_execute_);
}

bool Form::get_signed() const
{
	return (this->signed_);
}

void Form::be_signed(const Bureaucrat& b)
{
	if (b.get_grade() > this->grade_to_sign_)
	{
		throw GradeTooLowException();
	}
	this->signed_ = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Error: Grade is too high");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Error: Grade is too low");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form name: " << f.get_name()
	    << "\nGrade to sign: " << f.get_grade_to_sign()
	    << "\nGrade to execute: " << f.get_grade_to_execute()
	    << "\nIs signed: " << f.get_signed() << std::endl;
	return (out);
}
