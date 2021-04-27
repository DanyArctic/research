#include <iostream>
#include <vector>
#include <iterator>

/* Дан массив, состоящий из целых чисел.
 * Напишите программу, которая определяет, есть ли в массиве пара соседних элементов с одинаковыми знаками.

Входные данные
Сначала задано число NN — количество элементов в массиве (1≤N≤10000).
Далее через пробел записаны NN чисел — элементы массива. Массив состоит из целых ненулевых чисел, каждое из которых по модулю не превышает 10000.

Выходные данные
Необходимо вывести "YES", если существует пара соседних элементов с одинаковыми знаками. В противном случае следует вывести "NO". */

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> num{};
    int insert = 0;
    std::string answer = "NO";
    /*for (std::istream_iterator<int> p{std::cin}, e; p != e; ++p)
    {
        num.push_back(*p);
    }*/
    while(std::cin >> insert)
    {
        num.push_back(insert);
    }
    for (int i = 0; i <= num.size(); ++i)
    {
        if ((num[i] * num[i + 1]) > 0)
        {
            answer = "YES";
        }
    }
    std::cout << answer << std::endl;
    return 0;
}