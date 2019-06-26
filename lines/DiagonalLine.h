#pragma once
#include "BaseLine.h"
class DiagonalLine :
	public BaseLine
{
public:
	DiagonalLine(int length, string _char, Position position);
	~DiagonalLine();

	void print();
};

