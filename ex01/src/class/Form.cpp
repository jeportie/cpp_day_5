/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:43:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/02 10:16:06 by jeportie         ###   ########.fr       */
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
}

Form::Form(const std::string& name, size_t signGrade, size_t execGrade)
: _name(name)
, _isSigned(false)
, _reqSignGrade(signGrade)
, _reqExecGrade(execGrade)
{
	std::cout << "[Form] - default constructor called - " << std::endl;
}

Form::Form(const Form& src)
: _name("copy")
, _reqSignGrade(75)
, _reqExecGrade(75)
{
	std::cout << "[Form] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Form::~Form(void)
{
	std::cout << "[Form] - destructor called - " << std::endl;
	return;
}

Form & Form::operator=(const Form& rhs)
{
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

void	Form::beSigned(Bureaucrat& employee)
{
	return ;
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
