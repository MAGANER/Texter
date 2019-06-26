#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include"lines/BaseLine.h"

/*
 symbol is made of lines, symbols are used to made word
 word contains vector of symbols
*/
class Symbol
{
private:
	int length; // length of symbol is the same width

	vector<BaseLine*> lines; // load all lines into the vector


	vector<vector<char>> symbol; // final symbol
	void init_empty_symbol();   //fill matrix with empty lines

	void make_up_symbol(); // make 2d vector of lines
	void set_horizontal_line_to_symbol_2d_vector(BaseLine* line);
	void set_vertical_line_to_symbol_2d_vector(BaseLine* line);
	void set_left_diagonal_line_to_symbol_2d_vector(BaseLine* line);
	void set_right_diagonal_line_to_symbol_2d_vector(BaseLine* line);

	int compute_line_length(string size);
public:
	Symbol(vector<BaseLine*>& lines, int length);
	vector<vector<char>>& get_matrix();

	void print();
	~Symbol();
};

