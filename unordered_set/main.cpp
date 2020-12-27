#include <iostream>
#include "UnorderedSet.h"

int main()
{
    UnorderedSet my_set;
    try
    {
        my_set.insert("B");
    }
    catch (std::exception& e)
    {
        std::cout << "Exception occurred";
    }
    if (my_set.find("B"))
    {
        std::cout << "find" << '\n';
    }
    else
    {
        std::cout << "not find" << '\n';
    }
    return 0;
}
