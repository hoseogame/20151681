#include <Windows.h>
#include "SetCursur.h"

void SetCursurPosition(short x, short y){
	COORD cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

