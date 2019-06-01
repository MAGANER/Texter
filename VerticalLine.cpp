#include "VerticalLine.h"

VerticalLine::VerticalLine(int length, string _char, Position position) :
	BaseLine(length,_char,position)
{
	type = "vertical";
}
VerticalLine::~VerticalLine()
{
}


void VerticalLine::print()
{
	for (size_t i = 0; i < characters.size(); ++i)
	{
		cout << characters[i] << endl;
	}
}

