#pragma once
#include <iostream>
#include "Node.h"

class List
{
public:
    List() = default;

    ~List() = default;

    void print();

    int size();

    void push_back(const int val);

    void push_front(const int val);

    void pop_back();
private:

    Node *front_ = nullptr;
    Node *back_ = nullptr;

};
