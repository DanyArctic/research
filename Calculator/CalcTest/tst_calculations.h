#ifndef TST_SDFSDF_H
#define TST_SDFSDF_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../engine.h"

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &qString, ::std::ostream *os)
{
    *os << "\"" << qUtf8Printable(qString) << "\"";
}
QT_END_NAMESPACE
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

/*TEST(CalculatorTests, expression_test)
{
    Interaction calculator;
    EXPECT_EQ(5, calculator.calculate_expression("2+3"));
    EXPECT_EQ(10, calculator.calculate_expression("2+3+5"));
    EXPECT_EQ(0, calculator.calculate_expression("2+3-5"));
    EXPECT_EQ(23, calculator.calculate_expression("23"));
    EXPECT_EQ(0, calculator.calculate_expression(""));
}*/

TEST(CalculatorTests, postfix_notation_test)
{
    Interaction calculator;
    EXPECT_EQ("1 5 +", calculator.postfix_notation("1+5").join(" "));
    EXPECT_EQ("1 5 +", calculator.postfix_notation("(1+5)").join(" "));
    EXPECT_EQ("1 5 4 * +", calculator.postfix_notation("1+5*4").join(" "));
    EXPECT_EQ("11 5 + 4 *", calculator.postfix_notation("(11+5)*4").join(" "));
    EXPECT_EQ("", calculator.postfix_notation("").join(" "));
    EXPECT_EQ("14", calculator.postfix_notation("14").join(" "));
    EXPECT_THAT(calculator.postfix_notation("1+5"), testing::ElementsAreArray({"1", "5", "+"}));
}


TEST(CalculatorTests, tokenizer)
{
    Interaction calculator;
    EXPECT_EQ("2,+,3", calculator.tokenize("2+3").join(","));
    EXPECT_EQ("(,2,+,3,)", calculator.tokenize("(2+3)").join(","));
    EXPECT_EQ("", calculator.tokenize("").join(","));
    EXPECT_EQ("2", calculator.tokenize("2").join(","));
    EXPECT_EQ("24,+,334", calculator.tokenize("24+334").join(","));
}

#endif // TST_SDFSDF_H
