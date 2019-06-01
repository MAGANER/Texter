#include "Symbol.h"
Symbol::Symbol(vector<BaseLine*>& lines, int length)
{
	symbol.resize(length * 2);

	this->lines = lines;
	this->length = length;
	this->lines = lines;

	make_up_symbol();
}
Symbol::~Symbol()
{
}

void Symbol::make_up_symbol()
{
	for (size_t i = 0; i < lines.size(); ++i)
	{
		string type = lines[i]->get_type();
		if (type == "horizontal")
		{
			set_horizontal_line_to_symbol_2d_vector(lines[i]);

			//TODO:make correct printing of symbol
			for (size_t i = 0; i < symbol.size(); ++i)
			{
				cout << symbol[i].size() << endl;
			}
			
		}
	}
}
void Symbol::set_horizontal_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();

	vector<char> _line;
	_line.resize(length);
	for (int line_symb = x_pos; line_symb < length; ++line_symb)
	{
		char symb = line->get_line().at(0);
		_line[line_symb] = symb;
	}
	symbol[y_pos] = _line;
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