#pragma once
#include"VerticalLine.h"
#include"HorizontalLine.h"
#include<map>
#include<vector>
#include<fstream>
using namespace std;

/*
 this class contains information about lines
 of each symbol that will be used in programm
*/
class SymbolTable
{
private:
	map<string, vector<LineType>> table;
	vector<string> table_values;
	void load_table();
	void parse_table();

	string convert_char_to_string(char value);
	int convert_char_to_int(char value);
public:
	SymbolTable();
	~SymbolTable();

	vector<BaseLine*> generate_symbol_lines(string _char, int length);
};

