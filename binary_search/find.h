#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <memory>

int find(const std::vector<int> *array, int target)
{
    if (array == nullptr || array->empty() || array->front() > array->back())
    {
        return -1;
    }
    std::unique_ptr<int> min(new int(0));
    std::unique_ptr<int> max(new int(array->size() - 1));
    std::unique_ptr<int> middle(new int(std::midpoint(*min, *max))); //альтернатива (min+max)/2
    std::unique_ptr<int> cnt(new int(0));
    std::unique_ptr<bool> found(new bool(false));
    while (*min <= *max)
    {
        ++*cnt;
        *middle = std::midpoint(*min, *max);
        if ((*array)[*middle] < target)
        {
            *min = *middle + 1;
        }
        else if ((*array)[*middle] > target)
        {
            *max = *middle - 1;
        }
        else //(array[*middle] == target)
        {
            std::cout << "number of iterations is: " << *cnt << '\n';
            found = std::make_unique<bool>(true);
            break;
        }
    }
    if (!*found.get())
    {
        *middle = -1;
        std::cout << "not found" << '\n';
    }
    return *middle;
}