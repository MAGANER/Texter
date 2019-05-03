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
void App::get_length()
{
	cout << "enter length:";
	cin >> length;
}
void App::get_text_symbol()
{
	cout << "enter the symbol, whom should be used to create text:";
	cin >> text_symbol;
}
void App::get_path_to_save()
{
	cout << "enter FULL path to save text:";
	cin >> file_path;
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
			get_length();
			get_text_symbol();

			create_word();
			word.print();


			get_path_to_save();
			word.save(file_path);
		}
		break;
	}
}
void App::create_word()
{
	for (size_t i = 0; i < text_to_convert.size(); ++i)
	{

		String str(text_to_convert[i]);
		string standart_str = str.toAnsiString();
		vector<BaseLine*> lines = table.generate_symbol_lines(standart_str, text_symbol, length);
		Symbol* symbol = new Symbol(lines, length);
		word.add_word(symbol);
	}
	word.combine_word(length);
}