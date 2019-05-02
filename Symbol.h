#pragma once
#include<iostream>
#include<vector>
using namespace std;

#include"BaseLine.h"

/*
 symbol is made of lines, symbols are used to made word
*/
class Symbol
{
private:
	int length;

	vector<BaseLine*> lines;
	vector<vector<char>> symbol;
	void init_empty_symbol();
	bool is_line_empty(size_t line_number);

	void make_up_symbol(); // make 2d vector of lines
	void set_horizontal_line_to_symbol_2d_vector(BaseLine* line);
public:
	Symbol(vector<BaseLine*>& lines, int length);

	void print();
	~Symbol();
};

