#include "List.h"
#include "Node.h"


int List::size()
{
    Node* current = front_;
    int cnt = 0;
    while (current != nullptr)
    {
        ++cnt;
        current = current->next();
    }
    return cnt;
}

void List::push_back(const int val)
{
    Node *current = new Node(val);
    if (size() == 0)
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
}

void List::print()
{
    Node* current = front_;
    while (current != nullptr)
    {
        std::cout << current->get_value();
        current = current->next();
    }
}