#include <iostream>

void fb_alg(int number)
{
    bool fizz = number % 3 == 0;
    bool buzz = number % 5 == 0;
    if (fizz && buzz)
    {
        std::cout << "Fizz Buzz";
    }
    else if (fizz)
    {
        std::cout << "Fizz";
    }
    else if (buzz)
    {
        std::cout << "Buzz";
    }
    else
    {
        std::cout << number;
    }
}

int main()
{
    int val = 1;
    int max = 0;
    std::cout << "enter the max number, to which u want to count:" << '\n';
    std::cin >> max;
    while (val <= max)
    {
        fb_alg(val);
        ++val;
        if (val == max + 1)
        {
            break;
        }
        std::cout << ", ";
    }
    return 0;
}