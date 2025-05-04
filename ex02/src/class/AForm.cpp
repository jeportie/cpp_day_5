/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:43:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 18:11:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

AForm::AForm(void)
: _name("default")
, _isSigned(false)
, _reqSignGrade(75)
, _reqExecGrade(75)
{
	if (DEBUG)
		std::cout << "[AForm] - default constructor called - " << std::endl;
	if (this->_reqSignGrade < 1 || this->_reqExecGrade < 1)
		throw AForm::GradeTooHighException("Init Grade Error: 1 is the highest possible grade.");
	else if (this->_reqSignGrade > 150 || this->_reqExecGrade > 150)
		throw AForm::GradeTooLowException("Init Grade Error: 150 is the lowest possible grade.");
}

AForm::AForm(const std::string& name, size_t signGrade, size_t execGrade)
: _name(name)
, _isSigned(false)
, _reqSignGrade(signGrade)
, _reqExecGrade(execGrade)
{
	if (DEBUG)
		std::cout << "[AForm] - default constructor called - " << std::endl;
	if (this->_reqSignGrade < 1 || this->_reqExecGrade < 1)
		throw AForm::GradeTooHighException("Init Grade Error: 1 is the highest possible grade.");
	else if (this->_reqSignGrade > 150 || this->_reqExecGrade > 150)
		throw AForm::GradeTooLowException("Init Grade Error: 150 is the lowest possible grade.");
}

AForm::AForm(const AForm& src)
: _name("copy")
, _reqSignGrade(75)
, _reqExecGrade(75)
{
	if (DEBUG)
		std::cout << "[AForm] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout << "[AForm] - destructor called - " << std::endl;
	return;
}

AForm & AForm::operator=(const AForm& rhs)
{
	if (DEBUG)
		std::cout << "[AForm] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		_isSigned = rhs.isSigned();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const AForm& in)
{
	out << in.getName() << ", sign grade "
		<< in.getReqSignGrade() << ", exec grade " 
		<< in.getReqExecGrade() << ", is signed: "
		<< in.isSigned() << ".";
	return (out);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const std::string& AForm::getName(void) const { return (this->_name); }

bool	AForm::isSigned(void) const { return (this->_isSigned); }

size_t	AForm::getReqSignGrade(void) const { return (this->_reqSignGrade); }

size_t	AForm::getReqExecGrade(void) const { return (this->_reqExecGrade); }

bool	AForm::beSigned(Bureaucrat& employee)
{
	if (employee.getGrade() <= this->_reqSignGrade)
	{
		this->_isSigned = true;
		return (true);
	}
	else
		throw AForm::GradeTooLowException("Error: Employee grade is too low.");
	return (false);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) throw()
: _message(msg)
{
	if (DEBUG)
		std::cout << "[AForm-GradeToHighException] - constructor called - " << std::endl;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	if (DEBUG)
		std::cout << "[AForm-GradeToHighException] - destructor called - " << std::endl;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* AForm::GradeTooHighException::what() const throw()
{
    return (this->_message.c_str());
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) throw()
: _message(msg)
{
	if (DEBUG)
		std::cout << "[AForm-GradeToLowException] - constructor called - " << std::endl;
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	if (DEBUG)
		std::cout << "[AForm-GradeToLowException] - destructor called - " << std::endl;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* AForm::GradeTooLowException::what() const throw()
{
    return (this->_message.c_str());
}
