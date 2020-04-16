#include <iostream>

int main ()
{
    int user_num = 0;
    std::cin >> user_num;
    int i;
    int sum = 0;
    for (i = 1; i <= user_num; i++)
    {
      sum += i;          
    }
    std::cout << sum << "\n";
    return 0;
}