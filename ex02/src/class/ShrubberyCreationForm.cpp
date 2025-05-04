/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:42:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 18:05:33 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "../../include/main.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>


ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 145, 137)
, _target("default")
{
	if (DEBUG)
		std::cout << "[ShrubberyCreationForm] - default constructor called - " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137)
, _target(target)
{
	if (DEBUG)
		std::cout << "[ShrubberyCreationForm] - copy constructor called - " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
: AForm(src)
, _target(src._target)
{
	if (DEBUG)
		std::cout << "[ShrubberyCreationForm] - copy constructor called - " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << "[ShrubberyCreationForm] - destructor called - " << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (DEBUG)
		std::cout << "[ShrubberyCreationForm] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLowException("Form is not signed.");
	if (executor.getGrade() > getReqExecGrade())
		throw AForm::GradeTooLowException("Executor grade is too low.");
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("Failed to open file.");

	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\\\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "      // \\\\" << std::endl;

	ofs.close();
}
