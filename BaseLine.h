#pragma once
#include<iostream>
#include<string>
#include<deque>
using namespace std;

struct Position
{
	int x, y;
};
struct LineType
{
	Position position;
	string type;
};
/*
 line is element that is used to
 make symbol.
 there are 2 kinds of lines:
 vertical and horizontal
*/
class BaseLine
{
private:
	int x_moving_len, y_moving_len;

	void move_by_x();
	void move_by_y();
protected:
	deque<string> characters;
	int length;
	string _char;
	Position position;

	string type;
public:
	BaseLine(int length, string _char,Position position);
	virtual ~BaseLine();
	deque<string>& get_characters();
	string get_line();
	

	int get_x_moving_len();
	int get_y_moving_len();
	string get_type();

	virtual void print()=0;
public:
	enum X_position
	{
		left   = 1,
		center = 2,
		right  = 3
	};
	enum Y_position
	{
		top    = 1,
		middle = 2,
		bottom = 3
	};
};

