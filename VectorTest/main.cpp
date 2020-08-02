#include <iostream>
#include <vector>
#include "gtest/gtest.h"


class Vector //лучше исп. в названиях CamelCase
{
public:
    Vector() = default;

    ~Vector()
    {
        delete[] array_;
    }

    void push_back(int value) // 8
    {
        int *temp_array = array_; // {5}
        array_ = new int[position_ + 1]; // {0, 0}
        for (int i = 0; i < position_; ++i)
        {
            array_[i] = temp_array[i];
        } // {5, 0}
        array_[position_] = value; // {5, 8}
        ++position_;
        delete[] temp_array;
    }

    int get_value(int index) const // {5 7 2 8} 0 -> 5 //копирование и создание ссылки для простых переменных одинаково трудозатратно, поэтому оправдано для векторов и тп
    {
        return array_[index];
    }

    int size() const // эта функция ни при каких обстоятельствах не меняеет переменные класса
    {
        return position_;
    }

    void pop_back()
    {
        array_[position_] = 0; // 8 3 5 0 0 0 0 0 0 0
        --position_;
    }

    bool empty() const
    {
        /*
        Example:

        int a = 0;
    bool b = a; // false
    bool c = !a; //true
    return a; // return false

    First try:
    if (position_ == 0)
    {
        return true;
    }
    return false; // false == 0

    Second try:
   bool is_empty = !position_;
    return is_empty;

    bool is_not_empty = position_;
    return !is_not_empty;


    Third try:
    */

        return !position_; // 3 -> is vector empty? False, no, there are 3 numbers
    }

private:
    int *array_ = nullptr; // 0 0 0 0 // когда используем указатель, то всегда пишем "new", смотри в ф-ции push_back
    int position_ = 0;
}; // обязательно ; в конце классов!

/*CamelCase
snake_case*/

TEST(TypeOfTests, empty_vector_returns_size_0)
{
    Vector testing;
    EXPECT_EQ(0, testing.size()) << "test failed";
}

TEST(TypeOfTests, function_empty_returns_true_if_array_is_empty)
{
    Vector testing;
    EXPECT_EQ(testing.empty(), true) << "first part of test failed";
    EXPECT_EQ(0, testing.size()) << "second part of test failed";
}

TEST(TypeOfTests, vector_with_seven_numbers_returns_size_7)
{
    Vector testing;
    testing.push_back(1);
    testing.push_back(5);
    testing.push_back(7);
    testing.push_back(3);
    testing.push_back(8);
    testing.push_back(2);
    testing.push_back(8);
    EXPECT_EQ(7, testing.size()) << "test failed";
}

TEST(TypeOfTests, second_value_returns_right_number)
{
    Vector testing;
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

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// написать g_test тест