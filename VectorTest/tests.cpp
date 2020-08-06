#include <gtest/gtest.h>
#include "vector.h"

TEST(VectorTests, empty_vector_returns_size_0)
{
    Vector<std::string> testing;
    EXPECT_EQ(0, testing.size());
}

TEST(VectorTests, function_empty_returns_true_if_array_is_empty)
{
    Vector<double> testing;
    EXPECT_TRUE(testing.empty()) << "first part of test failed";
    EXPECT_EQ(0, testing.size()) << "second part of test failed";
}

TEST(VectorTests, vector_with_seven_numbers_returns_size_7)
{
    Vector<int> testing;
    testing.push_back(1);
    testing.push_back(5);
    testing.push_back(7);
    testing.push_back(3);
    testing.push_back(8);
    testing.push_back(2);
    testing.push_back(8);
    EXPECT_EQ(7, testing.size()) << "test failed";
}

TEST(VectorTests, second_value_returns_right_number)
{
    Vector<int> testing;
    testing.push_back(8);
    testing.push_back(3);
    testing.push_back(47);
    testing.push_back(1);
    testing.push_back(8);
    testing.push_back(6);
    testing.push_back(7);
    testing.push_back(4);
    testing.push_back(7);
    EXPECT_EQ(47, testing.get_value(2)) << "test failed";
}

TEST(VectorTests, third_value_returns_right_word)
{
    Vector<std::string> testing;
    testing.push_back("yo");
    testing.push_back("how");
    testing.push_back("are");
    testing.push_back("you");
    EXPECT_EQ("you", testing.get_value(3)) << "";
}

TEST(VectorTests, allocated_memory_increase)
{
    Vector<int> testing;
    int expected_num = 1;
    for (int i = 0; i < 33; ++i)
    {
        testing.push_back(rand());
        if (expected_num < i + 1)
        {
            expected_num *= 2;
        }
        EXPECT_EQ(expected_num, testing.get_size_allocated_memory()) << "after push_back was called " << i << " times, allocated_memory should be " << expected_num;
        EXPECT_EQ(i + 1, testing.size());
    }
}
