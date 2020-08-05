#include <iostream>
#include <vector>
#include <gtest/gtest.h>


template<typename T>
class Vector //лучше исп. в названиях CamelCase
{
public:
    Vector() = default;

    ~Vector()
    {
        delete[] array_;
    }

    const T& operator[](int index) const
    {
        return array_[index];
    }

    int get_size_allocated_memory() const
    {
        return allocated_memory_;
    }

    void push_back(T value) // 8
    {
        T *temp_array = array_; // {5}
        if (position_ > 0 && allocated_memory_ <= position_)
        {
            allocated_memory_ = allocated_memory_ * 2;
        }
        array_ = new T[allocated_memory_]; // {0, 0}
        for (int i = 0; i < position_; ++i)
        {
            array_[i] = temp_array[i];
        } // {5, 0}
        array_[position_] = value; // {5, 8}
        ++position_;
        delete[] temp_array;
    }

    const T& get_value(int index) const // {5 7 2 8} 0 -> 5 //копирование и создание ссылки для простых переменных одинаково трудозатратно, поэтому оправдано для векторов и тп
    {
        return array_[index];
    }

    int size() const // эта функция ни при каких обстоятельствах не меняеет переменные класса
    {
        return position_;
    }

    void pop_back()
    {
        array_[position_] = T(); // 8 3 5 0 0 0 0 0 0 0
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
    T *array_ = nullptr; // 0 0 0 0 // когда используем указатель, то всегда пишем "new", смотри в ф-ции push_back
    int position_ = 0;
    int allocated_memory_ = 1;
}; // обязательно ; в конце классов!

/*CamelCase
snake_case*/

TEST(TypeOfTests, empty_vector_returns_size_0)
{
    Vector<std::string> testing;
    EXPECT_EQ(0, testing.size());
}

TEST(TypeOfTests, function_empty_returns_true_if_array_is_empty)
{
    Vector<double> testing;
    EXPECT_TRUE(testing.empty()) << "first part of test failed";
    EXPECT_EQ(0, testing.size()) << "second part of test failed";
}

TEST(TypeOfTests, vector_with_seven_numbers_returns_size_7)
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

TEST(TypeOfTests, second_value_returns_right_number)
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

TEST(TypeOfTests, third_value_returns_right_word)
{
    Vector<std::string> testing;
    testing.push_back("yo");
    testing.push_back("how");
    testing.push_back("are");
    testing.push_back("you");
    EXPECT_EQ("you", testing.get_value(3)) << "test failed";
}

TEST(VectorTests, allocated_memory_increase)
{
    Vector<int> testing;
    for (int i = 0; i < 33; ++i)
    {
        testing.push_back(rand());
    }
    EXPECT_EQ(64, testing.get_size_allocated_memory()) << "test failed";
    EXPECT_EQ(33, testing.size()) << "test failed";
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
