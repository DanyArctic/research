#ifndef TST_SDFSDF_H
#define TST_SDFSDF_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../engine.h"

using namespace testing;

TEST(CalculatorTests, sum_func_returns_sum_of_first_and_sec_values)
{
    Interaction calculator;
    EXPECT_EQ(17, calculator.sum(7,10)) <<  "summary is not correct";
}

TEST(CalculatorTests, subtraction_func_returns_difference_of_first_and_sec_values)
{
    Interaction calculator;
    EXPECT_EQ(-10027, calculator.subtraction(17,10044)) <<  "difference is not correct";
}

TEST(CalculatorTests, expression_test)
{
    Interaction calculator;
    EXPECT_EQ(5, calculator.calculate_expression("2+3"));
    EXPECT_EQ(10, calculator.calculate_expression("2+3+5"));
    EXPECT_EQ(0, calculator.calculate_expression("2+3-5"));
    EXPECT_EQ(23, calculator.calculate_expression("23"));
    EXPECT_EQ(0, calculator.calculate_expression(""));
}

#endif // TST_SDFSDF_H
