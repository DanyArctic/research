#include <iostream>
#include "Client.h"

int main()
{
    Client player;
    std::cout << "Please enter your name: " << std::endl;
    std::string name;
    std::cin >> name;
    player.set_players_name(name);
    while (player.get_win_state() == 0)
    {
        int x = 0;
        int y = 0;
        std::cout << "Make your move, by coordinates x and y, from 0 to 2, with space between them: " << std::endl;
        std::cin >> x >> y;
        if (x < 0 || x >= Client::board_size_ || y < 0 || y >= Client::board_size_)
        {
            std::cout << "Wrong set. Try again." << std::endl;
            continue;
        }
        player.current_cell_set(x, y);
        system("cls");
        player.print_field();
    }
    //restart function?
}