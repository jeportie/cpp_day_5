/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 07:25:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 08:18:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "Intern.hpp"
#include "../../include/main.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	if (DEBUG)
		std::cout << "[Intern] - default constructor called - " << std::endl;
}

Intern::Intern(const Intern& src)
{
	if (DEBUG)
		std::cout << "[Intern] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << "[Intern] - destructor called - " << std::endl;
	return;
}

Intern & Intern::operator=(const Intern& rhs)
{
	if (DEBUG)
		std::cout << "[Intern] - copy assignment operator called - " << std::endl;
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[3])(const std::string&) const = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			AForm* form = (this->*formCreators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cerr << "Error: Form name '" << name << "' is not recognized" << std::endl;
	return NULL;
}

AForm* Intern::createShrubberyForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}
