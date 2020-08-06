#pragma once

template<typename T>
class Vector //лучше исп. в названиях CamelCase
{
public:
    Vector()
        : position_(0),
          allocated_memory_(1)
    {
        array_ = new T[allocated_memory_];
    }

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
        bool check_create_new_array = position_ > 0 && allocated_memory_ <= position_;
        if (check_create_new_array)
        {
            allocated_memory_ = allocated_memory_ * 2;
            array_ = new T[allocated_memory_]; // {0, 0}
        }
        for (int i = 0; i < position_; ++i)
        {
            array_[i] = temp_array[i];
        } // {5, 0}
        array_[position_] = value; // {5, 8}
        ++position_;
        if (check_create_new_array)
        {
            delete[] temp_array;
        }
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
    int allocated_memory_ = 0;
}; // обязательно ; в конце классов!

/*CamelCase
snake_case*/
