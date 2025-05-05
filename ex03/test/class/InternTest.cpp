/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InternTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 08:15:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Intern.hpp"

TEST(InternTest, DefaultConstructor)
{
    Intern intern;
    EXPECT_TRUE(true);
}

TEST(InternTest, CopyConstructor)
{
    Intern intern1;
    Intern intern2(intern1);
    EXPECT_TRUE(true);
}

TEST(InternTest, AssignmentOperator)
{
    Intern intern1;
    Intern intern2;
    intern2 = intern1;
    EXPECT_TRUE(true);
}

TEST(InternTest, MakeShrubberyForm)
{
    Intern intern;
    testing::internal::CaptureStdout();
    AForm* form = intern.makeForm("shrubbery creation", "garden");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(form, nullptr);
    EXPECT_EQ(form->getName(), "ShrubberyCreationForm");
    EXPECT_EQ(output, "Intern creates ShrubberyCreationForm\n");
    
    delete form;
}

TEST(InternTest, MakeRobotomyForm)
{
    Intern intern;
    testing::internal::CaptureStdout();
    AForm* form = intern.makeForm("robotomy request", "Bender");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(form, nullptr);
    EXPECT_EQ(form->getName(), "RobotomyRequestForm");
    EXPECT_EQ(output, "Intern creates RobotomyRequestForm\n");
    
    delete form;
}

TEST(InternTest, MakePresidentialForm)
{
    Intern intern;
    testing::internal::CaptureStdout();
    AForm* form = intern.makeForm("presidential pardon", "criminal");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(form, nullptr);
    EXPECT_EQ(form->getName(), "PresidentialPardonForm");
    EXPECT_EQ(output, "Intern creates PresidentialPardonForm\n");
    
    delete form;
}

TEST(InternTest, MakeInvalidForm)
{
    Intern intern;
    testing::internal::CaptureStderr();
    AForm* form = intern.makeForm("invalid form", "target");
    std::string output = testing::internal::GetCapturedStderr();
    
    EXPECT_EQ(form, nullptr);
    EXPECT_EQ(output, "Error: Form name 'invalid form' is not recognized\n");
}

