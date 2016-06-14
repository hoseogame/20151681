#ifndef  MANGCHI__H_
#define  MANGCHI__H_
#include "ctime.h"

class  MANGCHI{
private:
	int state;
	clock_t delay;

public:
	MANGCHI();

public:
	void SetState(int _state);
	int GetState();
};



#endif