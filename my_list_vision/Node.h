#pragma once

template<typename T>
class Node
{
public:
    Node(T data=T())
            : data_(data)
            , next_(nullptr)
            , prev_(nullptr)
    {

    }

    ~Node() = default;

    Node* next() const
    {
        return next_;
    }
    Node* prev() const
    {
        return prev_;
    }
    void set_next(Node* current)
    {
        next_ = current;
    }
    void set_prev(Node* current)
    {
        prev_ = current;
    }
    T get_value() const
    {
        return data_;
    }

private:
    T data_;
    Node* next_;
    Node* prev_;
};