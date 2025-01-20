/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:51:34 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 20:45:25 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class AForm
{
   public:
	AForm();
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm& o);
	AForm& operator=(const AForm& o);
	virtual ~AForm();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat& b);
	void CheckIfExecutionPossible(Bureaucrat const& executor) const;
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};

	class FormNotSignedException : public std::exception
	{
		const char* what() const noexcept override;
	};

   private:
	const std::string name_;
	const int grade_to_sign_;
	const int grade_to_execute_;
	bool signed_;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
