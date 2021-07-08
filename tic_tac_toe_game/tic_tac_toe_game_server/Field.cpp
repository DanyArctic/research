#include "Field.h"
#include <iostream>

void Field::print() const
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << (int)field_[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool Field::wrong_cell_set(size_t x, size_t y) const
{
	return x < 0 && x >= board_size_ && y < 0 && y >= board_size_ && field_[x][y] != CellState::Empty;
}

void Field::cell_set(size_t x, size_t y, CellState state_x_or_y)
{
	if (wrong_cell_set(x, y))
	{
		std::cout << "Wrong set. Try again." << std::endl;
	}
	field_[x][y] = state_x_or_y;
}

Field::WinState Field::winning_calc() const
{
	auto winner_cell_state = [](CellState state)
	{
		return state == CellState::X ? WinState::X : WinState::O;
	};

	if (field_[0][0] != CellState::Empty && field_[0][0] == field_[0][1] && field_[0][1] == field_[0][2] ||
		field_[0][0] == field_[1][1] && field_[1][1] == field_[2][2] ||
		field_[0][0] == field_[1][0] && field_[1][0] == field_[2][0])
	{
		return winner_cell_state(field_[0][0]);
	}
	if (field_[0][1] != CellState::Empty && field_[0][1] == field_[1][1] && field_[1][1] == field_[1][2])
	{
		return winner_cell_state(field_[0][1]);
	}
	if (field_[0][2] != CellState::Empty && field_[0][2] == field_[1][2] && field_[1][2] == field_[2][2] ||
		field_[0][2] == field_[1][1] && field_[1][1] == field_[2][0])
	{
		return winner_cell_state(field_[0][2]);
	}
	if (field_[1][0] != CellState::Empty && field_[1][0] == field_[1][1] && field_[1][1] == field_[1][2])
	{
		return winner_cell_state(field_[1][0]);
	}
	if (field_[2][0] != CellState::Empty && field_[2][0] == field_[2][1] && field_[2][1] == field_[2][2])
	{
		return winner_cell_state(field_[2][0]);
	}

	for (auto &column : field_)
		for (auto &cell : column)
			if (cell == CellState::Empty)
			{
				return WinState::Nobody;
			}

	return WinState::Tie;
}

void Field::clear_field()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			field_[i][j] = CellState::Empty;
		}
	}
}
