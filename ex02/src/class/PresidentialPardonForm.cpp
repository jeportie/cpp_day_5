/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:44:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 14:44:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "PresidentialPardonForm.hpp"
#include "../../include/main.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", 25, 5)
, _target("default")
{
    if (DEBUG)
        std::cout << "[PresidentialPardonForm] - default constructor called - " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5)
, _target(target)
{
    if (DEBUG)
        std::cout << "[PresidentialPardonForm] - default constructor called - " << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: AForm(src)
, _target(src._target)
{
    if (DEBUG)
        std::cout << "[PresidentialPardonForm] - copy constructor called - " << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    if (DEBUG)
        std::cout << "[PresidentialPardonForm] - destructor called - " << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (DEBUG)
        std::cout << "[PresidentialPardonForm] - copy assignment operator called - " << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!isSigned())
        throw AForm::GradeTooLowException("Form is not signed.");
    if (executor.getGrade() > getReqExecGrade())
        throw AForm::GradeTooLowException("Executor grade is too low.");
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
