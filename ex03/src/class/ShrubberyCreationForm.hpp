/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:42:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 08:15:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	void execute(Bureaucrat const& executor) const;

private:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	std::string _target;
};

#endif  // **************************************** SHRUBBERYCREATIONFORM_HPP //
