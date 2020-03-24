#include <iostream>
#include <string>

int main() {
    std::cout << "Hey there! I am Intel nEHb inside, human cyborg relations. What is your name?" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "It's pleasure to meet you, " << name << "! What year were you born in?" << std::endl;
    int curdate =2020;
    int bdate;
    std::cin >> bdate;
    std::cout << "That means thet you are " << curdate-bdate << " years old." << std::endl;
    return 0;
}