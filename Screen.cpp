#include "Screen.h"

Screen::Screen(){
	this->g_nScreenIndex = 0;
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개룰 만든다.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

Screen::~Screen(){
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void Screen::Flipping(){
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void Screen::Clear(){
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 55, Coor, &dw);
}

void Screen::Print(int x, int y, char *string){
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void Screen::SetColor(unsigned short color){
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}


