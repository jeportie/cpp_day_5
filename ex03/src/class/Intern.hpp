/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 07:25:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 07:44:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern& src);
	~Intern(void);

	Intern& operator=(const Intern& rhs);
	AForm* makeForm(const std::string& name, const std::string target);

private:
	AForm* createShrubberyForm(const std::string& target) const;
	AForm* createRobotomyForm(const std::string& target) const;
	AForm* createPresidentialForm(const std::string& target) const;
};

#endif  // ******************************************************* INTERN_HPP //
