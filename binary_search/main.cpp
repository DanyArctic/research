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
    while (true)
    {
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
            return *middle;
        }
        if (*middle == *max || *middle == *min)
        {
            return -1;
        }
    }
}

int main()
{
    std::vector<int> data{1,2,3,5,6,7,8,9,10};
    std::cout << find(data, 10);
    return 0;
}
