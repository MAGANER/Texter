#include "SymbolTable.h"
SymbolTable::SymbolTable()
{
	load_table();
	parse_table();
}
SymbolTable::~SymbolTable()
{
}

vector<BaseLine*> SymbolTable::generate_symbol_lines(string _char, int length)
{
	vector<BaseLine*> symbol_lines;
	vector<LineType> lines = table[_char];
	for (size_t i = 0; i < lines.size(); ++i)
	{
		BaseLine* line = NULL;
		if (lines[i].type == "vertical")
		{
			line = new VerticalLine(length, _char, lines[i].position);
		}
		if (lines[i].type == "horizontal")
		{
			line = new HorizontalLine(length, _char, lines[i].position);
		}

		symbol_lines.push_back(line);
	}

	return symbol_lines;
}
void SymbolTable::load_table()
{
	ifstream file("table.txt");
	string value;
	while (!file.eof())
	{
		file >> value;
		table_values.push_back(value);
	}
	file.close();
}
void SymbolTable::parse_table()
{
	string symbol;
	vector<LineType> line_types;

	for (size_t i = 0; i < table_values.size(); ++i)
	{
		string value = table_values[i];  // get current value
		unsigned int eq = value.find("="); // find pos of this symbol

		// get symbol, it must be before '='
		symbol = convert_char_to_string(value.at(eq - 1));

		int counter = eq + 1; // start after '='
		int max = value.size(); // get max value
		while (counter < max)
		{
			//skip if that is separator
			if (value[counter] == ',')
			{
				++counter;
			}

			LineType l_type;
			//first, get type
			if (value[counter] == 'v')
			{
				l_type.type = "vertical";
			}
			if (value[counter] == 'h')
			{
				l_type.type = "horizontal";
			}
			
			char x_pos = value[counter + 1];
			string str_x_pos = convert_char_to_string(x_pos);
			l_type.position.x = atoi(str_x_pos.c_str());


			char y_pos = value[counter + 2];
			string str_y_pos = convert_char_to_string(y_pos);
			l_type.position.y = atoi(str_y_pos.c_str());

			line_types.push_back(l_type);
			++counter;
		}

		//clear crap(yes, there are crap)
		vector<LineType> cleared_line_types;
		for (size_t i = 0; i < line_types.size(); ++i)
		{
			LineType l_type = line_types[i];
			if (l_type.type == "vertical" || l_type.type == "horizontal")
			{
				cleared_line_types.push_back(l_type);
			}
		}

		//put parsed data to table
		table[symbol] = cleared_line_types;
	}


}
string SymbolTable::convert_char_to_string(char value)
{
	char* str = &value;
	string* _str = new string(str);

	//get only first symbol,cos next ones are crap
	return _str->substr(0, 1);
}
int SymbolTable::convert_char_to_int(char value)
{
	return static_cast<int>(value);
}