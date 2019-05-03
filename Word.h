#pragma once
#include<vector>
#include"Symbol.h"
class Word
{
private:
	vector<Symbol*> symbols;
	vector<vector<char>> united_word;
	void add_symb_to_word(size_t symbol_number, int length);
	void add_empty_space_between_symbs(int last_symb_x_pos);
public:
	void add_word(Symbol* symb);
	void combine_word(int length);
	void print();
	Word();
	~Word();
};

