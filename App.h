#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

/*
 this class runs whole app
*/
class App
{
private:
	//text that will be converted and his parameters
	string text_to_convert;
	int width, height;
	char text_symbol;

	string entered_command;
	bool run_app; // while it's true programm runs

	int current_state;
	enum App_state
	{
		start,
		help,
		converting
	};
private:
	void print_welcome();
	void print_command_list();
	void get_user_input();
	void check_user_input();

	void get_text_to_convert();
	void get_width_and_height();
	void get_text_symbol();
public:
	App();
	~App();

	void run();
};

