#include <iostream>
#include <string>
using namespace std; /*что бы не исп
 * std везде, но это не очень хорошо*/

int main() {
    std::cout << "Do you want to buy ski or snowboard?" << std::endl; //just comment
    std::string answer;
    std::cin >> answer;
    if (answer == "ski")
    {
        std::cout << "loser! but okay, tell my your weight" << std::endl;
        int weight = 0;
        std::cin >> weight;
        if (weight < 60)
        {
            std:cout << "then sise of your ski is S" << std::endl;
        }
        else
        {
            std::cout << "Probably your sise will be Large" << std::endl;
        }
    }
    else if (answer == "snowboard")
    {
        std::cout << "yeah, boy!" << std::endl << "What's your weight then?" << std::endl;
        int weight = 0;
        std::cin >> weight;
        if (weight < 50)
        {
            std::cout << "Your sise of board is S" << std::endl;
        }
        else
        {
            std::cout << "Go to GYM!" << std::endl;
        }
    }
    else
    {
        std::cout << "ничего не понимаю, что ты говоришь" << std::endl;
    }

    return 0;
}
