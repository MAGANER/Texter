#pragma once
#include"BaseLine.h"
class HorizontalLine:
	public BaseLine
{
public:
	HorizontalLine(int length, string _char, Position position);
	~HorizontalLine();

	void print();
};

