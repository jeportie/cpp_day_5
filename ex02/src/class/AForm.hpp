/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:55:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 14:48:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm(void);
	AForm(const std::string& name, size_t reqSignGrade, size_t reqExecGrade);
	AForm(const AForm& src);
	~AForm(void);

	AForm& operator=(const AForm& rhs);

	const std::string& getName(void) const;
	bool	isSigned(void) const;
	size_t	getReqSignGrade(void) const;
	size_t	getReqExecGrade(void) const;
	bool	beSigned(Bureaucrat& employee);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException;
	class GradeTooLowException;

private:
	const std::string _name;
	bool			  _isSigned;
	const size_t	  _reqSignGrade;
	const size_t	  _reqExecGrade;
};

class AForm::GradeTooHighException : public std::exception
{
public:
	GradeTooHighException(const std::string& msg) throw();
	virtual ~GradeTooHighException() throw();

	virtual const char* what() const throw();

private:
	std::string _message;
};

class AForm::GradeTooLowException : public std::exception
{
public:
	GradeTooLowException(const std::string& msg) throw();
    virtual ~GradeTooLowException() throw();

	virtual const char* what() const throw();

private:
	std::string _message;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const AForm& in);

#endif  // ********************************************************* AFORM_HPP //
