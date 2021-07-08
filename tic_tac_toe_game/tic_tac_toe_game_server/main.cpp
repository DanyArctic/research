#include "Field.h"
#include "Server.h"
#include <iostream>
#include <cmath>
#include <string>


int main()
{
	//tests
	Field game;
	game.print();
	game.cell_set(0, 1, Field::CellState(2));
	game.print();
	game.clear_field();
	game.print();
	game.cell_set(0, 0, Field::CellState(2));
	game.cell_set(1, 1, Field::CellState(2));
	game.cell_set(2, 2, Field::CellState(2));
	game.print();

	Server serv;

	std::string player_one("Alice");
	std::string player_two("Daniel");
	
	serv.set_players_name(player_one, player_two);

	serv.first_or_second();
	int play = serv.get_play_order();
	std::cout << play << '\n';
	
	/*int next = serv.set_get_next_play_order();

	for (int i = 0; i < 5; ++i)
	{
		std::cout << next << '\n';
		next = serv.set_get_next_play_order();
	}*/
	Field::WinState game_result = Field::WinState::Nobody;

	game_result = game.winning_calc();
	
	switch (game_result)
	{
	case Field::WinState::Tie:
		std::cout << "Draw!" << std::endl;
		break;
	case Field::WinState::X:
		std::cout << player_one << " is the winner!" << std::endl;
		break;
	case Field::WinState::O:
		std::cout << player_two << " is the winner!" << std::endl;
		break;
	}

	return 0;
}