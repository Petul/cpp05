/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:00:29 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 21:12:06 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>
#include <string>

#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name_ << " signed form " << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException&)
	{
		std::cout << this->name_ << " couldn't sign form " << f.getName()
		          << " becuase its grade is too low." << std::endl;
	}
}
void Bureaucrat::executeForm(AForm const& f)
{
	try
	{
		f.execute(*this);
		std::cout << this->name_ << " executed form " << f.getName()
		          << std::endl;
	}
	catch (AForm::FormNotSignedException&)
	{
		std::cout << this->name_ << " couldn't execute form " << f.getName()
		          << " becuase the form is not signed." << std::endl;
	}
	catch (AForm::GradeTooLowException&)
	{
		std::cout << this->name_ << " couldn't execute form " << f.getName()
		          << " becuase its grade is too low." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name_ << " couldn't execute form " << f.getName()
		          << " becuase " << e.what() << std::endl;
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
