#pragma once
#include "BaseLine.h"
#include"HorizontalLine.h"
/*
 line that is printed verticaly, obviosly, i know
 to print in this way endl is used
*/
class VerticalLine :
	public BaseLine
{
public:
	VerticalLine(int length, string _char, Position position);
	~VerticalLine();

	void print();
};

