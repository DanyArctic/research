#pragma once
#include <vector>

class Field
{
public:
	Field()
	{
		
	};

	~Field() = default;

	enum class CellState
	{
		Empty,
		X,
		O,
	};

	enum class WinState
	{
		//Nobody,
		Tie,
		X,
		O,
	};
	
	void Print();

private:

	std::vector < std::vector <CellState> > field_ = 
	{ 
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty},
		{CellState::Empty, CellState::Empty, CellState::Empty}
	};
};
