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

# include <iostream>

class PresidentialPardonForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

private:
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const PresidentialPardonForm& in);

#endif  // *************************************** PRESIDENTIALPARDONFORM_HPP //
