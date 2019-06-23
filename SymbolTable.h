#pragma once
#include"lines/VerticalLine.h"
#include"lines/HorizontalLine.h"
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
	map<string, vector<LineType>> table; // after parsing table values are stored here
	vector<string> table_values; // first of all load data here
	void load_table(string path);//load data into table values
	void parse_table();  
	int get_table_symbs_max_number();

	string convert_char_to_string(char value);
	int convert_char_to_int(char value);
public:
	SymbolTable(); // create table, filled with parsed data 
	~SymbolTable();

	vector<BaseLine*> generate_symbol_lines(string text_symbol,string _char ,int length);
};

