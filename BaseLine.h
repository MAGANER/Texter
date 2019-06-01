#pragma once
#include<iostream>
#include<deque>
#include<string>
using namespace std;

struct Position
{
	int x, y;
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
	void move_by_x();
	void move_by_y();
protected:
	deque<string> characters;
	int length;
	string _char;
	Position position;
public:
	BaseLine(int length, string _char,Position position);
	virtual ~BaseLine();

	virtual void print()=0;
public:
	enum X_position
	{
		left,
		center,
		right
	};
	enum Y_position
	{
		top,
		middle,
		bottom
	};
};

