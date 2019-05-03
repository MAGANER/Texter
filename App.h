#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<SFML\System\String.hpp>
using namespace sf;
using namespace std;

#include"Word.h"
#include"SymbolTable.h"
/*
 this class runs whole app
*/
class App
{
private:
	SymbolTable table;
	Word word;

	string file_path;

	//text that will be converted and his parameters
	string text_to_convert;
	int length;
	string text_symbol;

	string entered_command;
	bool run_app; // while it's true programm runs

	int current_state;
	enum App_state
	{
		start,
		help,
		converting,
		save
	};
private:
	void print_welcome();
	void print_command_list();
	void get_user_input();
	void check_user_input();

	void get_text_to_convert();
	void get_length();
	void get_text_symbol();
	void get_path_to_save();

	void create_word();
public:
	App();
	~App();

	void run();
};

