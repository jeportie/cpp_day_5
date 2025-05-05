/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:41 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/02 09:55:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/PresidentialPardonForm.hpp"
#include "../../src/class/RobotomyRequestForm.hpp"

TEST(AFormTestPres, ParametricConstructor)
{
    PresidentialPardonForm f("Bob");
    EXPECT_EQ(f.getName(), "PresidentialPardonForm");
    EXPECT_FALSE(f.isSigned());
    EXPECT_EQ(f.getReqSignGrade(), 20);
    EXPECT_EQ(f.getReqExecGrade(), 5);
}

TEST(AFormTestRobot, ParametricConstructor)
{
    RobotomyRequestForm f("Bob");
    EXPECT_EQ(f.getName(), "RobotomyRequestForm");
    EXPECT_FALSE(f.isSigned());
    EXPECT_EQ(f.getReqSignGrade(), 72);
    EXPECT_EQ(f.getReqExecGrade(), 45);
}

TEST(AFormShrubbery, ParametricConstructor)
{
    RobotomyRequestForm f("Bob");
    EXPECT_EQ(f.getName(), "ShrubberyCreationFile");
    EXPECT_FALSE(f.isSigned());
    EXPECT_EQ(f.getReqSignGrade(), 145);
    EXPECT_EQ(f.getReqExecGrade(), 137);
}
