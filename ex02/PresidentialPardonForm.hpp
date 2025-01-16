/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:32:55 by pleander          #+#    #+#             */
/*   Updated: 2025/01/16 21:34:07 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
   public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& o);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& o);
	~PresidentialPardonForm() override;

	void execute(Bureaucrat const& executor) const override;

   private:
	std::string target_;
};

#endif
