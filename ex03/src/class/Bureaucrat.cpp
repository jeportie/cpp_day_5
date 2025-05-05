/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:06:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 18:09:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
Bureaucrat::Bureaucrat(void)
: _name("default")
, _grade(75)
{
	if (DEBUG)
		std::cout << "[Bureaucrat] - default constructor called - " << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException("Init Error: 1 is the highest possible grade.");
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException("Init Error: 150 is the lowest possible grade.");
}

Bureaucrat::Bureaucrat(std::string name, size_t grade)
: _name(name)
, _grade(grade)
{
	if (DEBUG)
		std::cout << "[Bureaucrat] - parametric constructor called - " << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException("Init Error: 1 is the highest possible grade.");
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException("Init Error: 150 is the lowest possible grade.");
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
: _name(src.getName())
{
	if (DEBUG)
		std::cout << "[Bureaucrat] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "[Bureaucrat] - destructor called - " << std::endl;
	return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (DEBUG)
		std::cout << "[Bureaucrat] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat& in)
{
	out << in.getName() << ", bureaucrat grade "
		<< in.getGrade() << ".";
	return (out);
}

const std::string& Bureaucrat::getName(void) const { return (this->_name); }

size_t Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::gradeUp(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException("Increment Error: Already at highest grade!");
	this->_grade--;
}

void Bureaucrat::gradeDown(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException("Decrement Error: Already at lowest grade!");
	this->_grade++;
}


void Bureaucrat::signForm(AForm& form)
{
	if (form.beSigned(*this) == true)
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout	<< _name << " couldn't sign " << form.getName()
					<< " because grade is too low" << std::endl;
	return ;
}

void Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) throw()
  : _message(msg)
{
	if (DEBUG)
		std::cout << "[Bureaucrat-GradeToHighException] - constructor called - " << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	if (DEBUG)
		std::cout << "[Bureaucrat-GradeToHighException] - destructor called - " << std::endl;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (this->_message.c_str());
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) throw()
  : _message(msg)
{
	if (DEBUG)
		std::cout << "[Bureaucrat-GradeToLowException] - constructor called - " << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	if (DEBUG)
		std::cout << "[Bureaucrat-GradeToLowException] - destructor called - " << std::endl;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (this->_message.c_str());
}
