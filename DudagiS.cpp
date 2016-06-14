#include "Game.h"
#include <conio.h>
#include <iostream>
#include "GameSchedule.h"

int D(){
	Game dudagi;
	int keycode = 0;
	while (keycode != 'n'){
		dudagi.Ready();
		keycode = _getch();
		if (keycode == ' '){
			while (dudagi.GetTime() < 20){
				if (_kbhit()){
					dudagi.KBHit();
				}
				dudagi.Update();
				dudagi.Render();
			}
			dudagi.Result();
			keycode = _getch();
		}
	}
	return 0;
}