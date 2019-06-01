#pragma once
#include<iostream>
#include<vector>
using namespace std;

#include"BaseLine.h"

/*
 symbol is made of lines, symbols are used to made word
*/
class Symbol
{
private:
	vector<BaseLine*> lines;
	vector<vector<string>> symbol;

	void make_up_symbol(); // make 2d vector of lines
public:
	Symbol(vector<BaseLine*>& lines, int length);

	void print();
	~Symbol();
};

