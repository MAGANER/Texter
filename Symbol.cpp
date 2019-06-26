#include "Symbol.h"
Symbol::Symbol(vector<BaseLine*>& lines, int length)
{
	this->lines = lines;
	this->length = length;


	//init matrix
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
		if (type == "l_diagonal")
		{
			set_left_diagonal_line_to_symbol_2d_vector(lines[i]);
		}
		if (type == "r_diagonal")
		{
			//set_right_diagonal_line_to_symbol_2d_vector(lines[i]);
		}
	}
}
void Symbol::set_horizontal_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();
	char symb = line->get_line().at(0);
	string size = line->get_size();

	int cycle_limit = compute_line_length(size);
	int len = cycle_limit + x_pos; // x_pos is a start, cycle limit is end
	for (int line_symb = x_pos; line_symb < len; ++line_symb)
	{
		symbol[y_pos][line_symb] = symb;
	}
}
void Symbol::set_vertical_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();
	char symb = line->get_line().at(0);
	string size = line->get_size();
	int cycle_limit = compute_line_length(size);
	int len = cycle_limit + y_pos; // y_pos is a start, cycle limit is end
	for (int line_symb = y_pos; line_symb < len; ++line_symb)
	{
		symbol[line_symb][x_pos] = symb;
	}
}
void Symbol::set_left_diagonal_line_to_symbol_2d_vector(BaseLine* line)
{
	int x_pos = line->get_x_moving_len();
	int y_pos = line->get_y_moving_len();
	char symb = line->get_line().at(0);
	string size = line->get_size();
	int cycle_limit = compute_line_length(size);
	int y_len = cycle_limit + y_pos; // y_pos is a start, cycle limit is end
	int x_len = cycle_limit + x_pos; // the same

	int y_counter = y_pos;
	int x_counter = x_pos;
	while (y_counter < y_len && x_counter < x_len)
	{
		symbol[y_counter][x_counter] = symb;
		++y_counter;
		++x_counter;
	}
}
void Symbol::set_right_diagonal_line_to_symbol_2d_vector(BaseLine* line)
{
	//TODO
}

void Symbol::print()
{
	//length+1,cos symbol is too big and there is
	//useless part
	for (size_t line = 0; line < length+1; ++line)
	{
		for (size_t line_char = 0; line_char < length + 1; ++line_char)
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
vector<vector<char>>& Symbol::get_matrix()
{
	return symbol;
}

int Symbol::compute_line_length(string size)
{
	if (size == "half")
	{
		return length/2;
	}
	if (size == "full")
	{
		return length * 2;
	}
}