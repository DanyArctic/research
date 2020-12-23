#include <iostream>
#include "UnorderedSet.h"

int main()
{
    UnorderedSet my_set;
    try
    {
        my_set.insert("N");
    }
    catch (std::exception& e)
    {
        std::cout << "Exception occurred";
    }
    return 0;
}
