/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTest.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:41 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/30 10:02:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Bureaucrat.hpp"

TEST(TestSuitName, DefaultConstructor)
{
    Bureaucrat o;
    EXPECT_EQ(o.getName(), "default");
    EXPECT_EQ(o.getGrade(), 75);
}

TEST(TestSuitName, CopyConstructor)
{
    Bureaucrat o;
    Bureaucrat c(o);
    EXPECT_EQ(c.getName(), "default");
    EXPECT_EQ(c.getGrade(), 75);
}

TEST(TestSuitName, AssignmentOperator)
{
    Bureaucrat o("jerome", 10);
    Bureaucrat c;
    c = o;
    EXPECT_EQ(c.getName(), "default");
    EXPECT_EQ(c.getGrade(), 10);
}

/*TEST(TestSuitName, MethodeName)*/
/*{*/
/*    Bureaucrat object;*/
/*    testing::internal::CaptureStdout();*/
/*    obj.methodTested();*/
/*    std::string output = testing::internal::GetCapturedStdout();*/
/*    EXPECT_EQ(output, "ExpectedValue");*/
/*}*/
