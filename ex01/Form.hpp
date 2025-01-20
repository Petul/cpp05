/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:51:34 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 13:14:33 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class Form
{
   public:
	Form();
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form& o);
	Form& operator=(const Form& o);
	~Form();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat& b);

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
	const int grade_to_sign_;
	const int grade_to_execute_;
	bool signed_;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
