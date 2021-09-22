#pragma once
#include <string>
#include <iostream>
#include <random>

class Server
{
public:
	void set_players_name(const std::string& name_1, const std::string& name_2);
	void first_or_second(); //who plays first
	size_t get_play_order() const;
	size_t set_get_next_play_order();
private:
	std::string player_one_name_;
	std::string player_two_name_;
	size_t play_order_ = 0;
};