#ifndef TST_SDFSDF_H
#define TST_SDFSDF_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../engine.h"

using namespace testing;

TEST(CalculatorTests, summary_func_returns_sum_of_first_and_sec_values)
{
    Interaction calculator;
    EXPECT_EQ(17, calculator.summary(7,10)) <<  "suumary is not correct";
}

#endif // TST_SDFSDF_H
