#include <iostream>
#include "UnorderedSet.h"

int main()
{
    UnorderedSet my_set;
    try
    {
        my_set.insert("B");
        my_set.insert("A");

    }
    catch (std::exception& e)
    {
        std::cout << "Exception occurred";
    }
    if (my_set.find("A"))
    {
        std::cout << "find" << '\n';
    }
    else
    {
        std::cout << "not find" << '\n';
    }
    return 0;
}
