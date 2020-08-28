#include <iostream>
#include <cmath>

int main()
{
    int user_input = 0;
    std::cin >> user_input;
    int prime_num = 2; //тут храним простые числа
    while (prime_num < sqrt(user_input))
    {
        if (user_input % prime_num == 0)
        {
            std::cout << prime_num << " ";
            user_input /= prime_num;
        }
        else if (user_input % prime_num != 0 && prime_num == 2)
        ++prime_num;
        else
            ++++prime_num;
    }
    if (user_input != 1)
       std::cout << user_input << " ";
    return 0;
}