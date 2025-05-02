/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:43:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/02 10:30:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

Form::Form(void)
: _name("default")
, _isSigned(false)
, _reqSignGrade(75)
, _reqExecGrade(75)
{
	if (DEBUG)
		std::cout << "[Form] - default constructor called - " << std::endl;
	if (this->_reqSignGrade < 1 || this->_reqExecGrade < 1)
		throw Form::GradeTooHighException("Init Grade Error: 1 is the highest possible grade.");
	else if (this->_reqSignGrade > 150 || this->_reqExecGrade > 150)
		throw Form::GradeTooLowException("Init Grade Error: 150 is the lowest possible grade.");
}

Form::Form(const std::string& name, size_t signGrade, size_t execGrade)
: _name(name)
, _isSigned(false)
, _reqSignGrade(signGrade)
, _reqExecGrade(execGrade)
{
	if (DEBUG)
		std::cout << "[Form] - default constructor called - " << std::endl;
	if (this->_reqSignGrade < 1 || this->_reqExecGrade < 1)
		throw Form::GradeTooHighException("Init Grade Error: 1 is the highest possible grade.");
	else if (this->_reqSignGrade > 150 || this->_reqExecGrade > 150)
		throw Form::GradeTooLowException("Init Grade Error: 150 is the lowest possible grade.");
}

Form::Form(const Form& src)
: _name("copy")
, _reqSignGrade(75)
, _reqExecGrade(75)
{
	if (DEBUG)
		std::cout << "[Form] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << "[Form] - destructor called - " << std::endl;
	return;
}

Form & Form::operator=(const Form& rhs)
{
	if (DEBUG)
		std::cout << "[Form] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		_isSigned = rhs.isSigned();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const Form& in)
{
	out << in.getName() << ", sign grade "
		<< in.getReqSignGrade() << ", exec grade " 
		<< in.getReqExecGrade() << ", is signed: "
		<< in.isSigned() << "." << std::endl;
	return (out);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const std::string& Form::getName(void) const { return (this->_name); }

bool	Form::isSigned(void) const { return (this->_isSigned); }

size_t	Form::getReqSignGrade(void) const { return (this->_reqSignGrade); }

size_t	Form::getReqExecGrade(void) const { return (this->_reqExecGrade); }

bool	Form::beSigned(Bureaucrat& employee)
{
	if (employee.getGrade() <= this->_reqSignGrade)
	{
		this->_isSigned = true;
		return (true);
	}
	else
		throw Form::GradeTooLowException("Error: Employee grade is too low.");
	return (false);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) throw()
: _message(msg)
{
	if (DEBUG)
		std::cout << "[Form-GradeToHighException] - constructor called - " << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	if (DEBUG)
		std::cout << "[Form-GradeToHighException] - destructor called - " << std::endl;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* Form::GradeTooHighException::what() const throw()
{
    return (this->_message.c_str());
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) throw()
: _message(msg)
{
	if (DEBUG)
		std::cout << "[Form-GradeToLowException] - constructor called - " << std::endl;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	if (DEBUG)
		std::cout << "[Form-GradeToLowException] - destructor called - " << std::endl;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* Form::GradeTooLowException::what() const throw()
{
    return (this->_message.c_str());
}
