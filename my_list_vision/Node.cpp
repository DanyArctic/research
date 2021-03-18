#include "Node.h"

Node::Node(const int value)
    : value_(value)
    , next_(nullptr)
    , prev_(nullptr)
{

}

Node* Node::next() const
{
    return next_;
}

Node* Node::prev() const
{
    return prev_;
}

void Node::set_next(Node *current)
{
    next_ = current;
}

void Node::set_prev(Node *current)
{
    prev_ = current;
}

int Node::get_value() const
{
    return value_;
}
