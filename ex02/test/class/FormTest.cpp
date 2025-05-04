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
#include "../../src/class/Form.hpp"
#include "../../src/class/Bureaucrat.hpp"

TEST(FormTest, DefaultConstructor)
{
    Form f;
    EXPECT_EQ(f.getName(), "default");
    EXPECT_FALSE(f.isSigned());
    EXPECT_EQ(f.getReqSignGrade(), 75);
    EXPECT_EQ(f.getReqExecGrade(), 75);
}

TEST(FormTest, ParametricConstructor)
{
    Form f("form1", 20, 10);
    EXPECT_EQ(f.getName(), "form1");
    EXPECT_FALSE(f.isSigned());
    EXPECT_EQ(f.getReqSignGrade(), 20);
    EXPECT_EQ(f.getReqExecGrade(), 10);
}

TEST(FormTest, CopyConstructor)
{
    Form o;
    Form c(o);
    EXPECT_EQ(c.getName(), "copy");
    EXPECT_EQ(c.getReqSignGrade(), 75);
    EXPECT_EQ(c.getReqExecGrade(), 75);
}

TEST(FormTest, AssignmentOperator)
{
    Form       o("jerome", 20, 10);
    Bureaucrat e("bob", 1);
    o.beSigned(e);
    Form c;
    c = o;
    EXPECT_EQ(c.getName(), "default");
    EXPECT_EQ(c.getReqSignGrade(), 75);
    EXPECT_EQ(c.getReqExecGrade(), 75);
    EXPECT_TRUE(c.isSigned());
}

TEST(FormTest, GradeTooHighSignException)
{
    testing::internal::CaptureStderr();
    try
    {
        Form o("tooHigh", 0, 10);
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Init Grade Error: 1 is the highest possible grade.\n");
}

TEST(FormTest, GradeTooHighExecException)
{
    testing::internal::CaptureStderr();
    try
    {
        Form o("tooHigh", 10, 0);
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Init Grade Error: 1 is the highest possible grade.\n");
}

TEST(FormTest, GradeTooLowSignException)
{
    testing::internal::CaptureStderr();
    try
    {
        Form o("tooLow", 151, 10);
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Init Grade Error: 150 is the lowest possible grade.\n");
}

TEST(FormTest, GradeTooLowExecException)
{
    testing::internal::CaptureStderr();
    try
    {
        Form o("tooLow", 10, 151);
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Init Grade Error: 150 is the lowest possible grade.\n");
}

TEST(FormTest, BeSigned)
{
    Bureaucrat employee("Bob", 5);

    Form file("Test", 10, 10);
    file.beSigned(employee);
    EXPECT_TRUE(file.isSigned());

	Form file1("Test1", 1, 1);
    try
    {
		file1.beSigned(employee);
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    EXPECT_FALSE(file1.isSigned());
}

TEST(FormTest, BeSignedException)
{
    testing::internal::CaptureStderr();
    try
    {
        Bureaucrat employee("Bob", 5);
        Form       file("Test", 1, 1);
        file.beSigned(employee);
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Error: Employee grade is too low.\n");
}
