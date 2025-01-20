/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:08:33 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 13:29:56 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Form;
class Bureaucrat
{
   public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& f);

	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};

   private:
	const std::string name_;
	int grade_;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
