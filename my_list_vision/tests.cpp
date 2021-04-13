#include <gtest/gtest.h>
#include "List.h"

TEST(ListTests, empty_list_returns_size_0)
{
    List<int> testing;
    EXPECT_EQ(0, testing.get_size());
}

TEST(ListTests, add_five_elements_to_list_end_returns_size_5)
{
    List<int> testing;
    testing.push_back(4);
    testing.push_back(1);
    testing.push_back(534);
    testing.push_back(34);
    testing.push_back(47);
    testing.print();
    EXPECT_EQ(5, testing.get_size()) << " size function test failed";
}

TEST(ListTests, add_four_elements_to_list_front_returns_size_4)
{
    List<int> testing;
    testing.push_front(4);
    testing.push_front(1);
    testing.push_front(534);
    testing.push_front(47);
    EXPECT_EQ(4, testing.get_size()) << "push_front test failed";
}

TEST(ListTests, deleting_last_element_shows_correct_data_and_size)
{
    List<int> testing;
    testing.push_front(4);
    testing.push_front(1);
    testing.push_front(534);
    testing.push_front(47);
    testing.pop_back();
    testing.print();
    EXPECT_EQ(3, testing.get_size()) << "pop_back test failed";
}

TEST(ListTests, deleting_first_element_shows_correct_data_and_size)
{
    List<int> testing;
    testing.push_front(4);
    testing.push_front(1);
    testing.push_front(534);
    testing.push_front(47);
    testing.push_front(686);
    testing.pop_front();
    testing.print();
    EXPECT_EQ(4, testing.get_size()) << "pop_front test failed";
}

TEST(ListTests, deleting_in_empty_list_returns_size_0)
{
    List<int> testing;
    testing.print();
    testing.pop_back();
    testing.pop_front();
    EXPECT_EQ(0, testing.get_size()) << "pop_functions in empty list failed";
}

TEST(ListTests, add_four_string_elements_to_list_end_returns_size_4)
{
    List<std::string> testing;
    testing.push_back("Hello");
    testing.push_back("beautiful");
    testing.push_back("world");
    testing.push_back("!");
    EXPECT_EQ(4, testing.get_size()) << " size function with string test failed";
}