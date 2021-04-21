#include <gtest/gtest.h>
#include "find.h"

TEST(SearchTests, perfect_condition_search_works_fine_and_return_element_position_7)
{
    std::vector<int> data{1,2,3,4,5,6,7,8,9,10};
    EXPECT_EQ(7, find(data, 8)) << "simple search failed";
}

TEST(SearchTests, perfect_condition_search_works_fine_and_return_element_position_7_test_two)
{
    std::vector<int> data{1,8,79,144,256,364,1720,2264,8795,9987129,123486761};
    EXPECT_EQ(4, find(data, 256)) << "simple search failed";
}

TEST(SearchTests, searching_first_element_returns_0)
{
    std::vector<int> data{1,2,3,5,6,7,8,9,10};
    EXPECT_EQ(0, find(data, 1)) << "search of first element failed";
}

TEST(SearchTests, searching_last_element_returns_9)
{
    std::vector<int> data{1,2,3,4,5,6,7,8,9,10};
    EXPECT_EQ(9, find(data, 10)) << "search of last element failed";
}

TEST(SearchTests, searching_middle_element_returns_9)
{
    std::vector<int> data{1,2,3,4,5,6,7,8,9,10,11};
    EXPECT_EQ(5, find(data, 6)) << "search of middle element failed";
}

TEST(SearchTests, searching_non_specified_element_returns_minus_1)
{
    std::vector<int> data{1,2,3,4,5,6,7,8,9,10};
    EXPECT_EQ(-1, find(data, 11)) << "search of non specified number failure";
}

TEST(SearchTests, searching_non_specified_element_returns_minus_1_test_two)
{
    std::vector<int> data{2,3,4,5,6,7,8,9,10,11};
    EXPECT_EQ(-1, find(data, 1)) << "search of non specified number failure";
}

TEST(SearchTests, searching_non_specified_element_returns_minus_1_test_tree)
{
    std::vector<int> data{1,3,4,5,6,7,8,9,10};
    EXPECT_EQ(-1, find(data, 2)) << "search of non specified number failure";
}