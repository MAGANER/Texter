#include "Word.h"
Word::Word()
{
}
Word::~Word()
{
}

void Word::add_word(Symbol* symb)
{
	symbols.push_back(symb);
}
void Word::print()
{
	for (size_t line = 0; line < united_word.size(); ++line)
	{
		vector<char> current_line = united_word[line];
		for (size_t symb = 0; symb < current_line.size(); ++symb)
		{
			cout << current_line[symb];
		}
		cout << endl;
	}
}
void Word::combine_word(int length)
{
	united_word.resize(length+1);
	for (size_t symb = 0; symb < symbols.size(); ++symb)
	{
		add_symb_to_word(symb, length);
	}
}
void Word::add_symb_to_word(size_t symbol_number, int length)
{
	vector<vector<char>> symb = symbols[symbol_number]->get_matrix();

	for (size_t line = 0; line < length + 1; ++line)
	{
		vector<char> current_line = symb[line];
		for (size_t character = 0; character < length + 1; ++character)
		{
			united_word[line].push_back(current_line[character]);

			// add space that separates symbols
			if (character == length)
			{
				united_word[line].push_back(' ');
			}
		}
	}
}