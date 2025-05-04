/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:43:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 18:46:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	void execute(Bureaucrat const& executor) const;

private:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	std::string _target;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const RobotomyRequestForm& in);

#endif  // ****************************************** ROBOTOMYREQUESTFORM_HPP //
