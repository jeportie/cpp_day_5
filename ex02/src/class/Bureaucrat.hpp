/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:21:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/04 18:07:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <iostream>
# include <string>
# include <exception>
# include "../../include/main.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(const Bureaucrat& src);

	~Bureaucrat(void);

	Bureaucrat& operator=(const Bureaucrat& rhs);

	const std::string& getName(void) const;
	size_t getGrade(void) const;

	void gradeUp(void); // decrement variable
	void gradeDown(void); //increment variable
	
	void signForm(AForm& form);
	void executeForm(AForm const& form) const;
	
	class GradeTooHighException;
	class GradeTooLowException;

private:
	const std::string _name;
	size_t		_grade;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
	GradeTooHighException(const std::string& msg) throw();
	virtual ~GradeTooHighException() throw();

	virtual const char* what() const throw();

private:
	std::string _message;
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
	GradeTooLowException(const std::string& msg) throw();
    virtual ~GradeTooLowException() throw();

	virtual const char* what() const throw();

private:
	std::string _message;
};

std::ostream & operator<<(std::ostream& out, const Bureaucrat& in);

#endif  // *************************************************** BUREAUCRAT_HPP //
