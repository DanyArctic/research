#pragma once
#include <iostream>
#include "Node.h"

class List
{
public:
    List()
    {
        size = 0;
    }

    ~List() = default;

    void print();

    int get_size();

    void push_back(const int val);

    void push_front(const int val);

    void pop_back();

    void pop_front();

    int size;
private:

    Node *front_ = nullptr;
    Node *back_ = nullptr;

};
