#include "DUDAGI.h"

DUDAGI::DUDAGI(){
	this->count = 2;
}

void DUDAGI::SetCount(int _count){
	this->count = _count;
}

int DUDAGI::GetCount(){
	return this->count;
}
