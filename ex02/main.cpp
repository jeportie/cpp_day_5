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
#include "src/class/AForm.hpp"
#include "src/class/PresidentialPardonForm.hpp"
#include "src/class/RobotomyRequestForm.hpp"
#include "src/class/ShrubberyCreationForm.hpp"

bool checkException(std::string name1, size_t grade1, std::string name2, size_t grade2)
{
    try
    {
		Bureaucrat  boss(name1, grade1);
		Bureaucrat	employee(name2, grade2);
		std::string target = "Bob";

		PresidentialPardonForm	pardon(target);
		RobotomyRequestForm robot(target);
		ShrubberyCreationForm tree(target);

		employee.signForm(pardon);
		std::cout << "==================================" << std::endl;
		employee.signForm(robot);
		std::cout << "==================================" << std::endl;
		employee.signForm(tree);
		std::cout << "==================================" << std::endl;

		boss.executeForm(pardon);
		std::cout << "==================================" << std::endl;
		boss.executeForm(robot);
		std::cout << "==================================" << std::endl;
		boss.executeForm(tree);
		std::cout << "==================================" << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) { std::cerr << e.what() << std::endl; }
    catch (const Bureaucrat::GradeTooHighException& e) { std::cerr << e.what() << std::endl; }
    catch (const AForm::GradeTooLowException& e) { std::cerr << e.what() << std::endl; }
    catch (const AForm::GradeTooHighException& e) { std::cerr << e.what() << std::endl; }
    catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
    catch (...) { std::cerr << "Unknown failure!" << std::endl; }
	std::cout << "==================================" << std::endl;
	return (true);
}

int main(void)
{
    checkException("Boss", 42, "sam", 60);
    checkException("Boss", 0, "sam", 120);
    checkException("Boss", 151, "sam", 120);
    checkException("Boss", 1, "sam", 0);
    checkException("Boss", 1, "sam", 151);
    checkException("Boss", 1, "sam", 25);
    checkException("Boss", 10, "sam", 72);
    return (0);
}
