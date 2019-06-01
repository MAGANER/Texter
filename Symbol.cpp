#include "Symbol.h"
Symbol::Symbol(vector<BaseLine*>& lines, int length)
{
	this->lines = lines;
	symbol.resize(length);

	make_up_symbol();
}
Symbol::~Symbol()
{
}

void Symbol::make_up_symbol()
{
}
void Symbol::print()
{
	for (size_t y = 0; y < symbol.size(); ++y)
	{
		for (size_t x = 0; x < symbol.size(); ++x)
		{
			cout << symbol[y][x];
		}
		cout << endl;
	}
}