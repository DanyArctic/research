#include "Client.h"

void Client::set_players_name(const std::string& name_1)
{
	player_name_ = name_1;
}

void Client::get_players_name()
{
	std::cout << player_name_;
}
