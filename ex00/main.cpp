/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:40:37 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/30 09:53:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/Bureaucrat.hpp"

bool checkException(std::string name, size_t grade, bool up)
{
    try
    {
		Bureaucrat employee(name, grade);

		if (up == true)
			employee.gradeUp();
		else
			employee.gradeDown();
		std::cout << employee << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
		std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
		std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
		std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
		std::cerr << "Unknown failure!" << std::endl;
    }
	return (true);
}

int main(void)
{
	checkException("TOBIG", 0, true);
	checkException("BIGEST", 1, true);
	checkException("TOSMALL", 151, false);
	checkException("SMALLEST", 150, false);
	checkException("Bob", 75, false);
    return (0);
}
