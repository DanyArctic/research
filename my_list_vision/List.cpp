#include "List.h"

int List::get_size()
{
    /*Node* current = front_;
    int cnt = 0;
    while (current != nullptr)
    {
        ++cnt;
        current = current->next();
    } //instead of counting here*/
    return size;
}

void List::push_back(const int val)
{
    Node *current = new Node(val);
    if (size == 0)
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
    ++size;
}

void List::push_front(const int val)
{
    Node *current = new Node(val);
    if (size == 0)
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
    ++size;
}

void List::print()
{
    Node* current = front_;
    while (current != nullptr)
    {
        std::cout << current->get_value() << ", ";
        current = current->next();
    }
}

void List::pop_back()
{
    Node* temp = back_;
    back_ = back_->prev();
    delete temp;
    back_->set_next(nullptr);
    --size;
}

void List::pop_front()
{
    Node* temp = front_;
    front_ = front_->next();
    delete temp;
    front_->set_prev(nullptr);
    --size;
}
