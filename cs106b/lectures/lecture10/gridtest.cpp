// Grid with Grid_Class.cpp : main project file.

#include <stdio.h>
// #include <conio.h>
#include <iostream>
#include <string>
#include "mygrid.h"
#include <windows.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using System::Console;

enum {
	black,          //  0
	dark_blue,      //  1
	dark_green,     //  2
	dark_cyan,      //  3
	dark_red,       //  4
	dark_magenta,   //  5
	dark_yellow,    //  6
	light_gray,     //  7
	dark_gray,      //  8
	light_blue,     //  9
	light_green,    // 10
	light_cyan,     // 11
	light_red,      // 12
	light_magenta,  // 13
	light_yellow,   // 14
	white           // 15
};

#define on , // So I can use the function - void text(text_color on background_color)
// To more easily remember which is text color vs background color

// Movement keys
#define ENTER 13
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

// My text color function. Use it if you wish.
void text(int text_color = 7 on int paper_color = 0)
{
	// defaults to light_gray on black
	int color_total = (text_color + (paper_color * 16));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_total);
}

void gotoXY(int x, int y);
void gotoXY(int x, int y, string text);
void Make_Grid(int style, int across, int down, int Single_Square_Width,
 int Single_Square_High, int Number_Squares_Wide,int Number_Squares_High,
 int f_color, int b_color, bool shadow, int shadow_fc, int shadow_bc);

int main()
{
	const int col = 38, row = 11;
	int x = 0, y = 0;
	int ch;
	bool moved = true;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	Grid<char> *grid = new Grid<char>(col,row);

	Console::SetWindowSize(80, 27);
	gotoXY(31, 1, "\"Make Grid\" Demo");

	Make_Grid(2, 0, 0, 78, 25, 1, 1, black, light_red, 0, 0, 0);
	Make_Grid(1, 1, 1, 1,1, col, row, black, light_cyan, 1, light_red, black);
	grid->set(2,2,'A');
	grid->set(0,0,'B');
	grid->set(1,3,'C');
	grid->set(4,0,'D');
	text(black on light_red);
	gotoXY(3,15,"Let's move the letter 'B'");
	text(black on light_cyan);
	do
	{
		// Not sure how to check if grid location 
		// is filled or empty before moving
		if(moved)
		{
			grid->set(x,y,'B');
		grid->Print();
		moved = false;
		}
		ch =_getch();
		if(ch==LEFT)
			if(x-1>=0)
			{
				grid->set(x,y,' ');
				x--;
				moved = true;
			}
			if(ch==RIGHT)
				if(x+1< col)
				{
					grid->set(x,y,' ');
					x++;
					moved = true;
				}
				if(ch==DOWN)
					if(y+1 < row)
					{
						grid->set(x,y,' ');
						y++;
						moved = true;
					}
					if(ch==UP)
						if(y-1>=0)
						{
							grid->set(x,y,' ');
							y--;
							moved = true;
						}
	}while (ch != ENTER);
	Console::SetWindowSize(80, 25);
	text(black on light_red);
	gotoXY(22, 24, "\xB5 Press any key to close program.. \xC6");
	_getch();
	return 0;
}

void gotoXY(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void gotoXY(int x, int y, string text)
{

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << text;
}

void Make_Grid(int style, int across, int down, int Single_Square_Width,
 int Single_Square_High, int Number_Squares_Wide, int Number_Squares_High,
 int f_color, int b_color, bool shadow, int shadow_fc, int shadow_bc)
{
	char Shadow = '\xB1';
	char  Grid[6][14] = {
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', '\xDA', '\xC4', '\xC2', '\xB3', '\xBF', '\xB3', '\xC3', '\xC4', '\xC5', '\xB4', '\xC0', '\xC1', '\xD9' },
		{ ' ', '\xC9', '\xCD', '\xCB', '\xBA', '\xBB', '\xBA', '\xCC', '\xCD', '\xCE', '\xB9', '\xC8', '\xCA', '\xBC' },
		{ ' ', '\xC9', '\xCD', '\xD1', '\xBA', '\xBB', '\xB3', '\xC7', '\xC4', '\xC5', '\xB6', '\xC8', '\xCF', '\xBC' },
		{ ' ', '\xD6', '\xC4', '\xD2', '\xBA', '\xB7', '\xBA', '\xC7', '\xC4', '\xD7', '\xB6', '\xD3', '\xD0', '\xBD' },
		{ ' ', '\xD5', '\xCD', '\xD1', '\xB3', '\xB8', '\xB3', '\xC6', '\xCD', '\xD8', '\xB5', '\xD4', '\xCF', '\xBE' },

	};

	int a, b, x, y;
	string Rail(Single_Square_Width, Grid[style][2]);
	string Line(Single_Square_Width, Grid[style][8]);
	string Middle(Single_Square_Width, ' ');

	text(f_color on b_color);

	// <<----------- Top Row ------------>

	gotoXY(across, down);
	cout << Grid[style][1];

	for (x = 0; x < Number_Squares_Wide; x++)
	{
		cout << Rail;
		if (x < Number_Squares_Wide - 1)
			cout << Grid[style][3];
		else
			cout << Grid[style][5];
	}
	down++;

	// <<----------- Middle Rows ------------>

	for (x = 0; x < Number_Squares_High; x++)
	{
		gotoXY(across, down);
		for (y = 0; y < Single_Square_High; y++)
		{
			gotoXY(across, down);
			cout << Grid[style][4];
			for (a = 0; a < Number_Squares_Wide; a++)
			{
				if (a < Number_Squares_Wide - 1)
					cout << Middle << Grid[style][6];
				else
					cout << Middle << Grid[style][4];
			}
			if (shadow)
			{
				text(shadow_fc on shadow_bc);
				cout << Shadow;
				text(f_color on b_color);
			}
			down++;
		}
		gotoXY(across, down);
		cout << Grid[style][7];
		for (b = 0; b < Number_Squares_Wide; b++)
		{
			cout << Line;
			if (b < Number_Squares_Wide - 1)
				cout << Grid[style][9];
			else
				cout << Grid[style][10];
		}
		if (shadow)
		{
			text(shadow_fc on shadow_bc);
			cout << Shadow;
			text(f_color on b_color);
		}
		down++;
	}
	down--;

	// <<----------- Bottom Row ------------>

	gotoXY(across, down);
	cout << Grid[style][11];

	for (x = 0; x < Number_Squares_Wide; x++)
	{
		cout << Rail;
		if (x < Number_Squares_Wide - 1)
			cout << Grid[style][12];
		else
			cout << Grid[style][13];

	}
	if (shadow)
	{
		text(shadow_fc on shadow_bc);
		string Grid_shadow(Number_Squares_Wide*(Single_Square_Width + 1) + 1, Shadow);
		gotoXY(across + 1, down + 1, Grid_shadow);
		text(f_color on b_color);
	}
}