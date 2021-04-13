#pragma once

#include <iostream>
#include "Node.h"

template<typename T>
class List
{
public:
    List()
            : size_(0), front_(nullptr), back_(nullptr)
    {

    }

    ~List()
    {
        Node<T> *current = front_;
        while (current != nullptr)
        {
            Node<T> *temp = current->next();
            delete current;
            current = temp;
        }
    }

    void print()
    {
        Node<T> *current = front_;
        while (current != nullptr)
        {
            if (current == back_)
            {
                std::cout << current->get_value();
                break;
            }
            std::cout << current->get_value() << ", ";
            current = current->next();
        }
    }

    int get_size()
    {
        /*Node* current = front_;
        int cnt = 0;
        while (current != nullptr)
        {
            ++cnt;
            current = current->next();
        } //instead of counting here*/
        return size_;
    }

    void push_back(T data)
    {
        Node<T> *current = new Node<T>(data); // верный ли синтаксиc в отношении исп. <T> как в инициализации, так и в присвоении?
        if (front_ == nullptr)
        {
            front_ = current;
            back_ = current;
        }
        else
        {
            current->set_prev(back_);
            back_->set_next(current);
            back_ = current;
        }
        ++size_;
    }

    void push_front(T data)
    {
        Node<T> *current = new Node<T>(data);
        if (front_ == nullptr)
        {
            front_ = current;
            back_ = current;
        }
        else
        {
            current->set_next(front_);
            front_->set_prev(current);
            front_ = current;
        }
        ++size_;
    }

    void pop_back()
    {
        if (size_ != 0)
        {
            Node<T> *temp = back_;
            back_ = back_->prev();
            delete temp;
            back_->set_next(nullptr);
            --size_;
        }
    }

    void pop_front()
    {
        if (size_ != 0)
        {
            Node<T> *temp = front_;
            front_ = front_->next();
            delete temp;
            front_->set_prev(nullptr);
            --size_;
        }
    }

private:
    int size_;
    Node<T> *front_ = nullptr;
    Node<T> *back_ = nullptr;

};
