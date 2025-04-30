/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTest.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:41 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/30 09:56:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/ClassName.hpp"

TEST(TestSuitName, DefaultConstructor)
{
    ClassName object;
    EXPECT_EQ(objArg1, "ExpectedValue");
}

TEST(TestSuitName, CopyConstructor)
{
    ClassName object;
    ClassName copy(object);
    EXPECT_EQ(copyArg1, "ExpectedValue");
}

TEST(TestSuitName, AssignmentOperator)
{
    ClassName object;
    ClassName copy(object);
    copy = original;
    EXPECT_EQ(copyGetterArg1(), "ExpectedValue");
}

TEST(TestSuitName, MethodeName)
{
    ClassName object;
    testing::internal::CaptureStdout();
    obj.methodTested();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ExpectedValue");
}
