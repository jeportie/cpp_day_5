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
#include "src/class/Form.hpp"

bool checkException(std::string name, size_t grade, size_t signGrade, size_t execGrade)
{
    try
    {
		Bureaucrat	employee(name, grade);
		Form		file("test", signGrade, execGrade);

		employee.signForm(file);
		std::cout << employee << std::endl;
		std::cout << file << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) { std::cerr << e.what() << std::endl; }
    catch (const Bureaucrat::GradeTooHighException& e) { std::cerr << e.what() << std::endl; }
    catch (const Form::GradeTooLowException& e) { std::cerr << e.what() << std::endl; }
    catch (const Form::GradeTooHighException& e) { std::cerr << e.what() << std::endl; }
    catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
    catch (...) { std::cerr << "Unknown failure!" << std::endl; }
	std::cout << "==================================" << std::endl;
	return (true);
}

int main(void)
{
	checkException("TOBIG", 0, 1, 1);
	checkException("TOSMALL", 151, 10, 10);
	checkException("Bob", 75, 80, 80);
	checkException("Bob", 75, 70, 70);
	checkException("Bob", 75, 75, 75);
    return (0);
}
