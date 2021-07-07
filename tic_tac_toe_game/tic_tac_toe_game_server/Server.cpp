#include "Server.h"

void Server::set_players_name(const std::string &name_1, const std::string& name_2)
{
	player_one_name_ = name_1;
	player_two_name_ = name_2;
}

void Server::first_or_second()
{
	std::random_device random_gen;
	std::mt19937 gen(random_gen());
	std::uniform_int_distribution<> distrib(1, 2);
	if (distrib(gen) == 1)
	{
		std::cout << player_one_name_ << ", your turn is first" << '\n';
		play_order_ = 1;
	}
	else
	{
		std::cout << player_two_name_ << ", your turn is first" << '\n';
		play_order_ = 2;
	}
}
