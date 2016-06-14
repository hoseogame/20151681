#ifndef GAME__H_
#define GAME__H_

#include "ctime.h"
#include "Screen.h"
#include "DUDAGI.h"
#include "MANGCHI.h"

enum GAME_STATE { INIT, READY, RUNNING, SUCCESS, FAILED, STOP, RESULT };

struct XY
{
	int nX, nY;
};

class Game:public Screen{
private:
	XY	g_Point[9];
	DUDAGI	*g_Dudagi[9];
	MANGCHI	g_Mangchi;
	int g_nDudagiCount; // 잡은 두더지 개수	
	clock_t g_timer;
	int ttime;

public:
	Game();

public:
	void MangchiAttack(int _x, int _y);
	void MangchiReady(int _x, int _y);

public:
	void Ready();
	void Result();

public:
	void Update();
	void Render();

public:
	int GetTime();

public:
	void KBHit();

};




#endif