#include <iostream>
#include <Windows.h>

using namespace std;

void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 10;
	SetConsoleCursorInfo(hStdout, &cursorInfo);
}

void DrawSquare(int x, int y, int width, int height, WORD colour, int ascii)
{
	width *= 2;
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, colour);
	gotoXY(x, y);
	for (int i = 0; i < width; i++)
	{
		cout << char(ascii);
	}
	int tempy = 0;
	while (tempy < height)
	{
		tempy++;
		gotoXY(x, y+tempy);
		cout << char(ascii);
		gotoXY(x+width-1, y+tempy);
		cout << char(ascii);
	}	
	gotoXY(x, y + height);
	for (int j = 0; j < width; j++)
	{
		cout << char(ascii);
	}
}

int main()
{

	DrawSquare(10, 0, 5, 5, FOREGROUND_RED, 177);
	DrawSquare(20, 10, 5, 5, FOREGROUND_GREEN, 177);
	DrawSquare(30, 0, 5, 5, FOREGROUND_BLUE, 177);

	gotoXY(0, 29);
	system("pause");
	return 0;
}