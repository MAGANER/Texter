#include "Line.h"

Line::Line(int length, char symbol, Position position, int view)
{
	this->length = length;
	this->symbol = symbol;
	this->position = position;

	move_line();
	set_line();
	
	this->view = view;
}
Line::~Line()
{
}
Position Line::get_position()
{
	return position;
}

void Line::print()
{
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (view == View::horizontal)
		{
			cout << line[i];
		}
		if (view == View::vertical)
		{
			cout << line[i] << endl;
		}
	}
}
void Line::set_line()
{
	for (size_t i = 0; i < length; ++i)
	{
		line.push_back(symbol);
	}
}
void Line::move_line()
{
	int x_move, y_move;

	//compute length of moving
	switch (position.x)
	{
	case X_position::center:
		x_move =(int) length / 2;
		break;
	case X_position::right:
		x_move = length;
		break;
	case X_position::left:
		x_move = 0;
		break;
	}
	switch (position.y)
	{
	case Y_position::middle:
		y_move =(int) length / 2;
		break;
	case Y_position::bottom:
		y_move = length;
		break;
	case Y_position::top:
		y_move = 0;
		break;
	}


	/*
	  set space or \n, cos after this symbols will be added
	*/
	for (size_t i = 0; i < y_move; ++i)
	{
		line.push_back('\n');
	}
	for (size_t i = 0; i < x_move; ++i)
	{
		line.push_back(' ');
	}
}