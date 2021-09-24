#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <utility>


class Client
{
public:
	enum class CellState
	{
		Empty,
		X,
		O,
	};

	enum class WinState
	{
		Nobody,
		Tie,
		X,
		O,
	};

	void set_players_name(const std::string& name_1);
	void print_field() const;
	static std::pair<int, int> current_cell_set(int x, int y);
	std::string get_players_name() const;
	int get_win_state();

	static const int board_size_ = 3;
private:
	std::string player_name_;
	WinState win_state_ = WinState::Nobody;
	std::vector < std::vector <CellState> > field_ =
	{
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty}
	};
};