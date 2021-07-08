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
	WinState winning_calc() const;

private:

	std::vector < std::vector <CellState> > field_ = 
	{ 
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty}
	};
	size_t board_size_ = 3;
};