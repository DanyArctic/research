#include "Field.h"
#include <iostream>

void Field::Print()
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
