/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:43:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 14:43:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "RobotomyRequestForm.hpp"
#include "../../include/main.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", 72, 45)
, _target("default")
{
	if (DEBUG)
		std::cout << "[RobotomyRequestForm] - default constructor called - " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45)
, _target(target)
{
	if (DEBUG)
		std::cout << "[RobotomyRequestForm] - copy constructor called - " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
: AForm(src)
, _target(src._target)
{
	if (DEBUG)
		std::cout << "[RobotomyRequestForm] - copy constructor called - " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << "[RobotomyRequestForm] - destructor called - " << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (DEBUG)
		std::cout << "[RobotomyRequestForm] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLowException("Form is not signed.");
	if (executor.getGrade() > getReqExecGrade())
		throw AForm::GradeTooLowException("Executor grade is too low.");
    std::cout << "Bzzzz... Bzzzz... Drilling noises..." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed on " << this->_target << "." << std::endl;
}
