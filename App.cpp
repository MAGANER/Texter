#include "App.h"
App::App()
{
	SetConsoleTitle("Texter");
	run_app = true;

	current_state = App_state::start;
}
App::~App()
{
}

void App::print_welcome()
{
	cout <<"                  welcome to TEXTER!" << endl << endl<<endl;
	cout << "type help or start" << endl;
}
void App::print_command_list()
{
	cout << "help: to read this text " << endl;
	cout << "start: to start convert text" << endl;
	cout << "fuck: to exit" << endl;
	cout << "license: to see full license text" << endl;
}
void App::run()
{
	print_welcome();
	while (run_app)
	{
		if(current_state != App_state::converting) get_user_input();
		system("cls");
		check_user_input();
	}
	
	
}
void App::get_user_input()
{
	cout << ">>";
	cin >> entered_command;
}
void App::get_text_to_convert()
{
	cout << "enter text to convert:";
	cin >> text_to_convert;
}
void App::get_width_and_height()
{
	cout << "enter width:";
	cin >> width;
	cout << endl;
	cout << "enter height:";
	cin >> height;
}
void App::get_text_symbol()
{
	cout << "enter the symbol, whom should be used to create text:";
	cin >> text_symbol;
}
void App::check_user_input()
{
	switch (current_state)
	{
	case App_state::start:
		if (entered_command == "help")
		{
			current_state = App_state::help;
			print_command_list();
		}
		if (entered_command == "start")
		{
			current_state = App_state::converting;
		}
		break;
	case App_state::help:
		if (entered_command == "help")
		{
			print_command_list();
		}
		if (entered_command == "start")
		{
			current_state = App_state::converting;
		}
		if (entered_command == "fuck")
		{
			run_app = false;
		}
		if (entered_command == "license")
		{
			//print_license_text();
		}
		break;
	case App_state::converting:
		if (entered_command == "start")
		{
			get_text_to_convert();
			get_width_and_height();
			get_text_symbol();
		}
		break;
	}
}