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

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "[RobotomyRequestForm] - default constructor called - " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
	std::cout << "[RobotomyRequestForm] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[RobotomyRequestForm] - destructor called - " << std::endl;
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "[RobotomyRequestForm] - copy assignment operator called - " << std::endl;
//	if (this != &rhs)
//		this->_foo = rhs.getFoo();
	return (*this);
}

//std::ostream & operator<<(std::ostream & out, const RobotomyRequestForm& in)
//{
	//out << "The value of _foo is : " << in.getFoo();
	//return (out);
//}

