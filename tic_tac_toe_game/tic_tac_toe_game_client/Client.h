#pragma once
#include <string>
#include <iostream>

class Client
{
public:
	void set_players_name(const std::string& name_1);
	void get_players_name();
private:
	std::string player_name_;
};

