#include "Field.h"
#include <iostream>

void Field::print()
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

/*void Field::clear()
{
	for (auto it : field_)
	{
		field_.emplace(CellState::Empty);
	}
}*/
