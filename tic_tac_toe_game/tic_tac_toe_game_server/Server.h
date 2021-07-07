#pragma once
#include <string>
#include <iostream>
#include <random>

class Server
{
public:
	void set_players_name(const std::string& name_1, const std::string& name_2);
	void first_or_second(); //who plays first

private:
	std::string player_one_name_ = nullptr;
	std::string player_two_name_ = nullptr;
	int play_order_ = 0;
};

