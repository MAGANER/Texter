#include "Symbol.h"
Symbol::Symbol(vector<BaseLine*>& lines, int length)
{
	symbol.resize(length * 2);
	init_empty_symbol();


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

			for (size_t i = 0; i < symbol.size(); ++i)
			{
				if (!is_line_empty(i))
				{
					print_symbol_line(i);
				}
				else
				{
					cout << endl;
				}
			}
			
		}
	}
}
void Symbol::set_horizontal_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();

	vector<char> _line;
	_line.resize(length*2);
	for (int line_symb = x_pos; line_symb < _line.size(); ++line_symb)
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

void Symbol::print_symbol_line(size_t symbol_line)
{
	if (symbol_line < symbol.size())
	{
		//print it
		for (size_t i = 0; i < symbol[symbol_line].size(); ++i)
		{
			cout << symbol[symbol_line][i];
		}
	}
}
void Symbol::init_empty_symbol()
{
	vector<char> empty_line;
	for (size_t i = 0; i < symbol.size(); ++i)
	{
		for (int n = 0; n < length; ++n)
		{
			empty_line.push_back(' ');
		}
		symbol[i] = empty_line;
	}
}
bool Symbol::is_line_empty(size_t line_number)
{
	vector<char> line = symbol[line_number];
	size_t empty_char_counter = 0;
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (line[i] == ' ')
		{
			empty_char_counter++;
		}
	}

	if (empty_char_counter == line.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}