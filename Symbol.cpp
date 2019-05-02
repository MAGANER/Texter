#include "Symbol.h"
Symbol::Symbol(vector<BaseLine*>& lines, int length)
{
	this->lines = lines;
	this->length = length;
	this->lines = lines;

	symbol.resize(length*2);//the height of symbol
	init_empty_symbol();

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
		}
		if (type == "vertical")
		{
			set_vertical_line_to_symbol_2d_vector(lines[i]);
		}
	}
}
void Symbol::set_horizontal_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();
	char symb = line->get_line().at(0);

	for (int line_symb = x_pos; line_symb < length*2; ++line_symb)
	{
		symbol[y_pos][line_symb] = symb;
	}
}
void Symbol::set_vertical_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();
	char symb = line->get_line().at(0);
	for (int line_symb = y_pos; line_symb < length * 2; ++line_symb)
	{
		symbol[line_symb][x_pos] = symb;
	}
}
void Symbol::print()
{
	//length+1,cos symbol is too big and there is
	//useless part
	for (size_t line = 0; line < length+1; ++line)
	{
		for (size_t line_char = 0; line_char < symbol[line].size(); ++line_char)
		{
			cout << symbol[line][line_char];
		}
		cout << endl;
	}
}
void Symbol::init_empty_symbol()
{
	vector<char> empty_line;
	empty_line.resize(length * 2);
	for (size_t i = 0; i < symbol.size(); ++i)
	{
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