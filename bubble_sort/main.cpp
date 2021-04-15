#include <iostream>
#include <vector>

void bubble(std::vector<int> &array)
{
    bool movement;
    while (movement)
    {
        movement = 0;
        for (int i = 0; i < array.size() - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                movement = true;
                std::swap(array[i], array[i + 1]);
            }
        }

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
