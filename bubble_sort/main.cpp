#include <iostream>
#include <vector>

void bubble(std::vector<int> &array)
{
    bool movement = true;
    int iterations = array.size() - 1;
    while (movement)
    {
        movement = false;
        for (int i = 0; i < iterations; ++i)
        {
            if (array[i] > array[i + 1])
            {
                movement = true;
                std::swap(array[i], array[i + 1]);
                /* array[i] += array[i + 1];
                 * array[i + 1] = array[i] - array[i + 1];
                 * array[i] -= array[i + 1];*/
            }
        }
        --iterations;
    }
}

int main()
{

    int size = 0;
    std::cout << "how many elts do u want to put in array: ";
    std::cin >> size;
    std::vector<int> numbers(size);
    std::cout << "enter elts separated by spaces: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
    bubble(numbers);
    std::cout << "sorted with bubble algorithm: " << '\n';
    for (auto it : numbers)
    {
        std::cout << it << " ";
    }
    return 0;
}
