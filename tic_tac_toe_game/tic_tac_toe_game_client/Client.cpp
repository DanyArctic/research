#include "Client.h"

void Client::set_players_name(const std::string& name_1)
{
	player_name_ = name_1;
}

std::string Client::get_players_name() const
{
	return player_name_;
}

int Client::get_win_state()
{
	return static_cast<int>(win_state_);
}

void Client::print_field() const
{
	std::cout << "#####" << std::endl;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::cout << static_cast<int>(field_[i][j]) << " ";
			}
			std::cout << std::endl;
		}
	std::cout << "#####" << std::endl;
    int casted_win_state = static_cast<int>(win_state_);
    if (casted_win_state != 0)
    {
        switch (casted_win_state)
        {
        case 1:
            std::cout << "Draw!" << std::endl;
            break;
        case 2:
            std::cout << "X is a winner!" << std::endl;
            break;
        case 3:
            std::cout << "O is a winner!" << std::endl;
            break;
        default:
            std::cout << "Wrong winner state input." << std::endl;
            break;
        }
        std::cout << "Game over." << std::endl;
    }
}

std::pair<int, int> Client::current_cell_set(int x, int y)
{
    return std::pair<int, int>(x, y);
}