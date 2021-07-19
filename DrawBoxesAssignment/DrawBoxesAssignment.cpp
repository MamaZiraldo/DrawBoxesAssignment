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

	for (int i = 0; i < height; i++)
	{
		gotoXY(x + i, y + i);
		cout << char(ascii);
		gotoXY((x + height - 1 - i), (y + i));
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