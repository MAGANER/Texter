#include "HorizontalLine.h"

HorizontalLine::HorizontalLine(int length, string _char, Position position):
	BaseLine(length,_char,position)
{
	type = "horizontal";
}
HorizontalLine::~HorizontalLine()
{
}

void HorizontalLine::print()
{
	for (size_t i = 0; i < characters.size(); ++i)
	{
		cout << characters[i];
	}
}
