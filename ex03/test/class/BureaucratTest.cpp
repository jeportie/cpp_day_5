/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTest.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:41 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/02 09:41:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Bureaucrat.hpp"
#include "../../src/class/PresidentialPardonForm.hpp"

TEST(BureaucratTest, DefaultConstructor)
{
    Bureaucrat o;
    EXPECT_EQ(o.getName(), "default");
    EXPECT_EQ(o.getGrade(), 75);
}

TEST(BureaucratTest, ParametricConstructor)
{
    Bureaucrat o("test", 75);
    EXPECT_EQ(o.getName(), "test");
    EXPECT_EQ(o.getGrade(), 75);
}

TEST(BureaucratTest, CopyConstructor)
{
    Bureaucrat o;
    Bureaucrat c(o);
    EXPECT_EQ(c.getName(), "default");
    EXPECT_EQ(c.getGrade(), 75);
}

TEST(BureaucratTest, AssignmentOperator)
{
    Bureaucrat o("jerome", 10);
    Bureaucrat c;
    c = o;
    EXPECT_EQ(c.getName(), "default");
    EXPECT_EQ(c.getGrade(), 10);
}

TEST(BureaucratTest, gradeUp_gradeDown)
{
    Bureaucrat o("jerome", 10);

    EXPECT_EQ(o.getGrade(), 10);
    o.gradeUp();
    EXPECT_EQ(o.getGrade(), 9);
    o.gradeDown();
    EXPECT_EQ(o.getGrade(), 10);
}

TEST(BureaucratTest, GradeTooHighException)
{
    testing::internal::CaptureStderr();
    try
    {
        Bureaucrat o("tooHight", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Init Error: 1 is the highest possible grade.\n");
}

TEST(BureaucratTest, GradeTooHighIncrementException)
{
    testing::internal::CaptureStderr();
    try
    {
        Bureaucrat o("tooHight", 1);
        o.gradeUp();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Increment Error: Already at highest grade!\n");
}

TEST(BureaucratTest, GradeTooLowException)
{
    testing::internal::CaptureStderr();
    try
    {
        Bureaucrat o("tooLow", 151);
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Init Error: 150 is the lowest possible grade.\n");
}

TEST(BureaucratTest, GradeTooLowDecrementException)
{
    testing::internal::CaptureStderr();
    try
    {
        Bureaucrat o("tooLow", 150);
        o.gradeDown();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Decrement Error: Already at lowest grade!\n");
}

TEST(BureaucratTest, signForm)
{
    Bureaucrat employee("Bob", 1);

    PresidentialPardonForm file("Bob");
    PresidentialPardonForm file1("Bob");
    testing::internal::CaptureStdout();
    employee.signForm(file);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(file.isSigned());
    EXPECT_EQ(output, "Bob signed PresidentialPardonForm\n");

    Bureaucrat intern("Jej", 100);
    testing::internal::CaptureStderr();
    try
    {
		intern.signForm(file1);
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output1 = testing::internal::GetCapturedStderr();
    EXPECT_FALSE(file1.isSigned());
    EXPECT_EQ(output1, "Error: Employee grade is too low.\n");
}

TEST(BureaucratTest, execForm)
{
    Bureaucrat employee("Jej", 1);
    PresidentialPardonForm file("Bob");

    employee.signForm(file);
    testing::internal::CaptureStdout();
    employee.executeForm(file);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Bob has been pardoned by Zaphod Beeblebrox.\nJej executed PresidentialPardonForm\n");

    Bureaucrat intern("Jej", 100);
    testing::internal::CaptureStderr();
    try
    {
		intern.executeForm(file);
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::string output1 = testing::internal::GetCapturedStderr();
    EXPECT_TRUE(file.isSigned());
    EXPECT_EQ(output1, "Jej couldn't execute PresidentialPardonForm because Executor grade is too low.\n");
}

/*TEST(BureaucratTest, template)*/
/*{*/
/*    Bureaucrat object;*/
/*    testing::internal::CaptureStdout();*/
/*    obj.methodTested();*/
/*    std::string output = testing::internal::GetCapturedStdout();*/
/*    EXPECT_EQ(output, "ExpectedValue");*/
/*}*/
