#include <iostream>
#include <string>

using namespace std; /*что бы не исп
 * std везде, но это не очень хорошо*/

int main() {
    std::cout << "Do you want to buy ski or snowboard?" << std::endl; //just comment
    std::string answer;
    std::cin >> answer;
    if (answer == "ski" || answer == "snowboard") {
        std::cout << "okay, tell my your weight" << std::endl;
        int weight = 0;
        std::cin >> weight;
        if (answer == "ski" && weight < 50) {
            std::cout << "then sise of your ski is S" << std::endl;
        } else if (answer == "ski" && weight > 70) {
            std::cout << "Probably your sise will be Large" << std::endl;
        } else if (answer == "ski") {
            std::cout << "then sise of your ski is Medium" << std::endl;
        } else {
            if (weight < 50) {
                std::cout << "Your sise of board is S" << std::endl;
            } else {
                std::cout << "Go to GYM!" << std::endl;
            }
        }
    } else {
        std::cout << "ничего не понимаю, что ты говоришь" << std::endl;
    }

    return 0;
}
