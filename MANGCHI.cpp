#include "MANGCHI.h"

MANGCHI::MANGCHI(){
	this->state = 0;
}

void MANGCHI::SetState(int _state){
	this->state = _state;
}

int MANGCHI::GetState(){
	return this->state;
}