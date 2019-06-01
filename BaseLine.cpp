#include "BaseLine.h"

BaseLine::BaseLine(int length, string _char, Position position)
{
	this->length = length;
	this->_char = _char;
	this->position = position;

	for (size_t i = 0; i < length; ++i)
	{
		characters.push_back(_char);
	}

	move_by_x();
	move_by_y();
}
BaseLine::~BaseLine()
{
}
void BaseLine::move_by_x()
{
	int moving_length = 0;
	string move_str = "";
	switch (position.x)
	{
	case X_position::left:
		//don't move
		break;
	case X_position::center:
		moving_length = (int)length / 2;
		break;
	case X_position::right:
		moving_length = length;
		break;
	}

	for (size_t i = 0; i < moving_length; ++i)
	{
		move_str += " ";
	}
	for (size_t i = 0; i < characters.size(); ++i)
	{
		characters[i].insert(0, move_str);
	}
}
void BaseLine::move_by_y()
{
	int moving_length = 0;
	switch (position.y)
	{
	case Y_position::top:
		//don't move
		break;
	case Y_position::middle:
		moving_length = (int)length / 2;
		break;
	case Y_position::bottom:
		moving_length = length;
		break;
	}

	for (size_t i = 0; i < moving_length; ++i)
	{
		characters.push_front("");
	}
}