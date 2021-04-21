#pragma once
#include <iostream>
#include <vector>
#include <numeric>

int find(std::vector<int> array, int point)
{
    if (array.empty() || array.front() > array.back())
    {
        return -1;
    }
    int *min = new int(0);
    int *max = new int(array.size() - 1);
    int *middle = new int(std::midpoint(*min, *max));
    int *cnt = new int(0);
    while (true)
    {
        ++*cnt;
        *middle = std::midpoint(*min, *max);
        if (array[*middle] < point)
        {
            *min = *middle + 1;
        }
        else if (array[*middle] > point)
        {
            *max = *middle - 1;
        }
        if (array[*middle] == point)
        {
            std::cout << "number of iterations is: " << *cnt << '\n'; //правильно ли считаются итерации? сложность?
            return *middle;
        }
        if (*middle == *max || *middle == *min)
        {
            return -1;
        }
    }
}