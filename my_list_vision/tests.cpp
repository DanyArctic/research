#include <gtest/gtest.h>
#include "List.h"

TEST(ListTests, empty_list_returns_size_0)
{
    List testing;
    EXPECT_EQ(0, testing.size());
}

TEST(ListTests, add_five_elements_to_list_end_returns_size_5)
{
    List testing;
    testing.push_back(4);
    testing.push_back(1);
    testing.push_back(534);
    testing.push_back(34);
    testing.push_back(47);
    EXPECT_EQ(5, testing.size()) << " size function test failed";
}

TEST(ListTests, add_four_elements_to_list_front_returns_size_4)
{
    List testing;
    testing.push_front(4);
    testing.push_front(1);
    testing.push_front(534);
    testing.push_front(47);
    EXPECT_EQ(4, testing.size()) << "push_front test failed";
}

TEST(ListTests, print_elements_from_list)
{
    List testing;
    testing.push_front(4);
    testing.push_front(1);
    testing.push_front(534);
    testing.push_front(47);
    testing.print();
    //ASSERT_STRNE("47, 534, 1, 4", testing.print()) << "print test failed";
}

