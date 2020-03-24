#include <iostream>
#include <string>
using namespace std; /*что бы не исп
 * std везде, но это не очень хорошо*/

int main() {
    std::cout << "Do you want to buy ski or snowboard?" << std::endl; //just comment
    std::string answer;
    std::cin >> answer;
    if (answer=="ski")
    {
        std::cout << "loser!" << std::endl;
    }
    else if (answer=="snowboard")
    {
        std::cout << "yeah, boy!" << std::endl;
    }
    else
    {
        std::cout << "ничего не понимаю, что ты говоришь" << std::endl;
    }
    return 0;
}
