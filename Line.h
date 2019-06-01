#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct Position
{
	int x, y;
};

/*
 this class is a part of symbol
*/
class Line
{
private:
	vector<char> line;
	void set_line(); 
	void move_line(); // relating to its position

	Position position;
	int length;
	int view;
	char symbol;

public:
	Line(int length, char symbol,Position position, int view);
	~Line();

	Position get_position();
	void print();

public:
	enum Y_position
	{
		top,
		middle,
		bottom
	};
	enum X_position
	{
		left,
		center,
		right
	};
	enum View
	{
		vertical,
		horizontal
	};
};

