#pragma once
#include<vector>
#include<fstream>
#include"Symbol.h"

class Word
{
private:
	vector<Symbol*> symbols;
	vector<vector<char>> united_word;
	void add_symb_to_word(size_t symbol_number, int length);
public:
	void add_word(Symbol* symb);
	void combine_word(int length);
	void print();
	void save(string file_path);

	Word();
	~Word();
};

