/*#include "Field.h"
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
	game.cell_set(0, 0, Field::CellState(1));
	game.cell_set(1, 1, Field::CellState(1));
	game.cell_set(2, 2, Field::CellState(1));
	game.print();
	game.clear_field();
	game.cell_set(2, 2, Field::CellState(1));
	game.print();
	//game.cell_set(2, 2, Field::CellState(1));

	Server serv;

	std::string player_one("Alice");
	std::string player_two("Daniel");
	
	serv.set_players_name(player_one, player_two);

	serv.first_or_second();
	int play = serv.get_play_order();
	std::cout << "play_order: " << play << '\n';
	
	/*int next = serv.set_get_next_play_order();

	for (int i = 0; i < 5; ++i)
	{
		std::cout << next << '\n';
		next = serv.set_get_next_play_order();
	}*/
	/*
	Field::WinState game_result = Field::WinState::Nobody;

	game_result = game.get_win_state(); //почему на пустом поле вылезает 3?
	std::cout << "game_result: " << (int)game_result << std::endl;

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
	default:
		std::cout << "No one is the winner yet!" << std::endl;
	}

	return 0;
}*/

#undef UNICODE


#include <cmath>
#include <iostream>
#include <vector>
#include "TCPServer.h"
#include "Field.h"
#include "Server.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

constexpr std::string_view DEFAULT_PORT = "27015";

int __cdecl main(void)
{
	Field game;
	Server engine;
    TCPServer serv;
	std::string input_name_player_one;
	try
	{
		addrinfo* result = serv.resolve_serv_adress_and_port(DEFAULT_PORT);
		serv.connect(result);

		// Receive until the peer shuts down the connection
		
		input_name_player_one = serv.receive(128);
		std::cout << input_name_player_one << std::endl;
    }
    catch (const std::runtime_error& error)
    {
        std::cerr << error.what() << '\n';
    }
	std::string player_two = "Second player";
	engine.set_players_name(input_name_player_one, player_two);

	//std::string p1 = { input[0] }; 
	//std::string p2 = { input[2] };
	//size_t res = std::stoll(p1); //saving input date of players move
	//size_t res2 = std::stoll(p2);
	////std::cout << res << ' ' << res2 << std::endl; trying to see integer results 

	//tests
	
	//game.cell_set(res, res2, Field::CellState(1));
	game.print();

	engine.first_or_second();
	int play = engine.get_play_order();
	std::cout << "play_order: " << play << '\n';

	int next = engine.set_get_next_play_order();
	
	Field::WinState game_result = Field::WinState::Nobody;
	game_result = game.get_win_state();
	
	while (game.get_win_state() == Field::WinState::Nobody)
	{
		std::string input = serv.receive(3);
		std::string p1 = { input[0] };
		std::string p2 = { input[2] };
		size_t res = std::stoll(p1); //saving input date of players move
		size_t res2 = std::stoll(p2);
		std::cout << res << ' ' << res2 << std::endl; //trying to see integer results 
		game.cell_set(res, res2, Field::CellState(1));
		game.print();
		std::cout << next << '\n';
		next = engine.set_get_next_play_order();
	}
	
	std::cout << "game_result: " << (int)game_result << std::endl;

	switch (game_result)
	{
	case Field::WinState::Tie:
		std::cout << "Draw!" << std::endl;
		break;
	case Field::WinState::X:
		std::cout << input_name_player_one << " is the winner!" << std::endl;
		break;
	case Field::WinState::O:
		std::cout << player_two << " is the winner!" << std::endl;
		break;
	default:
		std::cout << "No one is the winner yet!" << std::endl;
	}

	return 0;
}