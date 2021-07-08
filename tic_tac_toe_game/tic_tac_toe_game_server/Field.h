#pragma once
#include <vector>

class Field
{
public:
	Field() = default;

	~Field() = default;

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
	
	void print() const;
	void clear_field();
	bool wrong_cell_set(size_t x, size_t y) const;
	void cell_set(size_t x, size_t y, CellState state_x_or_y);
	WinState get_win_state() const;

private:
	bool check_win_combination(int x, int y) const;
	bool check_rows(int x, CellState cellState) const;
	bool check_columns(int y, CellState cellState) const;
	bool check_diagonals(CellState cellState) const;

	std::vector < std::vector <CellState> > field_ = 
	{ 
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty}
	};
	size_t board_size_ = 3;

	WinState win_state_ = WinState::Nobody;
	int cells_filled_ = 0;
};