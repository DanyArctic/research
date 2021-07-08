#include "Field.h"
#include <iostream>

void Field::print() const
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << static_cast<int>(field_[i][j]) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << static_cast<int>(win_state_) << std::endl  << std::endl;
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
	++cells_filled_;
	if (check_win_combination(static_cast<int>(x), static_cast<int>(y)))
	{
		win_state_ = state_x_or_y == CellState::X ? WinState::X : WinState::O;
	}
}

bool Field::check_rows(int x, CellState cellState) const
{
	int bingo = 0;
	for (int i = 0; i < field_.at(0).size(); ++i)
	{
		if (field_[x][i] == cellState)
			++bingo;
		else
			break;
	}
	return bingo == board_size_;
}

bool Field::check_columns( int y, CellState cellState) const
{
	int bingo = 0;
	for (int i = 0; i < field_.size(); ++i)
	{
		if (field_[i][y] == cellState)
			++bingo;
		else
			break;
	}
	return bingo == board_size_;
}

bool Field::check_diagonals(CellState cellState) const
{
	return (field_[0][0] == field_[1][1] && field_[1][1] == field_[2][2] && field_[2][2] == cellState) ||
			(field_[0][2] == field_[1][1] && field_[1][1] == field_[2][0] && field_[2][0] == cellState);
}

bool Field::check_win_combination(int x, int y) const
{
	if (field_.size() < x || field_.at(0).size() < y)
		return false;

	const CellState cellState = field_.at(x).at(y);

	return (check_rows(x, cellState) || check_columns(y, cellState) || check_diagonals(cellState) || cells_filled_ >= board_size_ * board_size_);
}

Field::WinState Field::get_win_state() const
{
	return win_state_;
}

void Field::clear_field()
{
	for (auto &column : field_)
	{
		for (auto &cell : column)
		{
			cell = CellState::Empty;
		}
	}
	cells_filled_ = 0;
	win_state_ = WinState::Nobody;
}
