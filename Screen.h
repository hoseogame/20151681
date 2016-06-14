#ifndef SCREEN__H_
#define SCREEN__H_
#include <windows.h>

class Screen{
private:
	int g_nScreenIndex;
	HANDLE g_hScreen[2];

public:
	Screen();
	virtual ~Screen();

public:
	void Flipping();
	void Clear();
	void Print(int x, int y, char *string);
	void SetColor(unsigned short color);
};

#endif