/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:00:29 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 13:35:34 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#include "Form.hpp"

Bureaucrat::Bureaucrat() : Bureaucrat("Default", 150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_{name}
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& o) : Bureaucrat(o.name_, o.grade_)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& o)
{
	if (this == &o)
	{
		return (*this);
	}
	this->grade_ = o.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (this->name_);
}

int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade_ - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade_ + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_++;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name_ << " signed form " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException&)
	{
		std::cout << this->name_ << " couldn't sign form " << f.getName()
		          << " because it's grade is too low" << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Error: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Error: Grade is too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}
