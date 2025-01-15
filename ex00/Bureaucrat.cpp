/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:00:29 by pleander          #+#    #+#             */
/*   Updated: 2025/01/15 21:38:12 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

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

std::string Bureaucrat::get_name() const
{
	return (this->name_);
}

int Bureaucrat::get_grade() const
{
	return (this->grade_);
}

void Bureaucrat::increment_grade()
{
	if (this->grade_ - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_--;
}

void Bureaucrat::decrement_grade()
{
	if (this->grade_ + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_++;
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
	out << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
	return (out);
}
