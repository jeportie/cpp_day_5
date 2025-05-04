/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:44:24 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 14:44:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	void execute(Bureaucrat const& executor) const;

private:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	std::string _target;
};

#endif  // *************************************** PRESIDENTIALPARDONFORM_HPP //
