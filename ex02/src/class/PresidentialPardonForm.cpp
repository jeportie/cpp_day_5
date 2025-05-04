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

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "[PresidentialPardonForm] - default constructor called - " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
	std::cout << "[PresidentialPardonForm] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[PresidentialPardonForm] - destructor called - " << std::endl;
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "[PresidentialPardonForm] - copy assignment operator called - " << std::endl;
//	if (this != &rhs)
//		this->_foo = rhs.getFoo();
	return (*this);
}

//std::ostream & operator<<(std::ostream & out, const PresidentialPardonForm& in)
//{
	//out << "The value of _foo is : " << in.getFoo();
	//return (out);
//}

