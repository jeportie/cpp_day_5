/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:40:37 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 08:17:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/Bureaucrat.hpp"
#include "src/class/AForm.hpp"
#include "src/class/Intern.hpp"

void testIntern()
{
    std::cout << "\n===== Testing Intern Class =====" << std::endl;
    
    Intern someRandomIntern;
    
    std::cout << "\n--- Creating RobotomyRequestForm ---" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Creating PresidentialPardonForm ---" << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
    if (ppf)
    {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n--- Creating ShrubberyCreationForm ---" << std::endl;
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf)
    {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    std::cout << "\n--- Creating Invalid Form ---" << std::endl;
    AForm* invalid = someRandomIntern.makeForm("invalid form", "Target");
    
    if (invalid)
    {
        delete invalid;
    }
    
    std::cout << "=================================" << std::endl;
}

int main(void)
{
    std::cout << "===== Testing Previous Functionality =====" << std::endl;
    testIntern();
    
    return (0);
}
