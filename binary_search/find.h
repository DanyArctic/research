#pragma once
#include <iostream>
#include <vector>
#include <numeric>

int find(std::vector<int> array, int target)
{
    if (array.empty() || array.front() > array.back())
    {
        return -1;
    }
    int *min = new int(0);
    int *max = new int(array.size() - 1);
    int *middle = new int(std::midpoint(*min, *max)); //альтернатива (min+max)/2
    int *cnt = new int(0);
    bool *found = new bool(false);
    while ((*min <= *max) && (*found != true))
    {
        ++*cnt;
        *middle = std::midpoint(*min, *max);
        if (array[*middle] < target)
        {
            *min = *middle + 1;
        }
        else if (array[*middle] > target)
        {
            *max = *middle - 1;
        }
        else //(array[*middle] == target)
        {
            *found = true;
            std::cout << "number of iterations is: " << *cnt << '\n'; //правильно ли считаются итерации? сложность?
            return *middle;
        }
    }
    std::cout << "not found" << '\n';
    return -1;
}