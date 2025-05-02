/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:55:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/02 10:29:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(const std::string& name, size_t reqSignGrade, size_t reqExecGrade);
	Form(const Form& src);
	~Form(void);

	Form& operator=(const Form& rhs);

	const std::string& getName(void) const;
	bool	isSigned(void) const;
	size_t	getReqSignGrade(void) const;
	size_t	getReqExecGrade(void) const;
	bool	beSigned(Bureaucrat& employee);

	class GradeTooHighException;
	class GradeTooLowException;

private:
	const std::string _name;
	bool			  _isSigned;
	const size_t	  _reqSignGrade;
	const size_t	  _reqExecGrade;
};

class Form::GradeTooHighException : public std::exception
{
public:
	GradeTooHighException(const std::string& msg) throw();
	virtual ~GradeTooHighException() throw();

	virtual const char* what() const throw();

private:
	std::string _message;
};

class Form::GradeTooLowException : public std::exception
{
public:
	GradeTooLowException(const std::string& msg) throw();
    virtual ~GradeTooLowException() throw();

	virtual const char* what() const throw();

private:
	std::string _message;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const Form& in);

#endif  // ********************************************************* FORM_HPP //
