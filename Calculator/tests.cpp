#include <gtest/gtest.h>
#include "engine.h"

TEST(CalculatorTests, summary_func_returns_sum_of_first_and_sec_values)
{
    Interaction calculator;
    EXPECT_EQ(17, calculator.summary(7,10)) <<  "suumary is not correct";
}
