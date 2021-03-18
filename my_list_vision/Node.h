#pragma once

class Node
{
public:
    Node(const int value);

    ~Node() = default;

    Node* next() const;
    Node* prev() const;
    void set_next(Node* current);
    void set_prev(Node* current);
    int get_value() const;

private:
    int value_;
    Node* next_;
    Node* prev_;
};