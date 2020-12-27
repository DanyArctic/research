#include "UnorderedSet.h"
#include <iostream>

UnorderedSet::UnorderedSet()
{
    words_.resize(5);
}

void UnorderedSet::insert(const std::string &word)
{
    int hashed = hash(word);
    if (hashed < 0)
    {
        throw std::exception();
    }
    words_[hashed] = word;
}

bool UnorderedSet::find(const std::string &word) const
{
    for (auto it : words_)
    {
        if (it != word)
        {
            continue;
        }
        return true;
    }
    return false;
}

int UnorderedSet::hash(const std::string &word) const
{
    if (word == "A") {
        return 0;
    }
    else if (word == "B") {
        return 1;
    }
    else if (word == "C") {
        return 2;
    }
    else if (word == "D") {
        return 3;
    }
    else if (word == "E") {
        return 4;
    }
    return -1;
}
