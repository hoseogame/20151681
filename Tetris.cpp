#include <iostream>
#include <conio.h>
#include "TetrisGame.h"
#include "GameSchedule.h"

int T(){
	TetrisGame tg;
	std::cout << "키 이동:←→ 순간이동:space 가속:↓ 회전: ↑ " << std::endl;
	std::cout << "시작하려면 아무 키나 누르세요" << std::endl;
	getch();
	system("cls");
	while (tg.Update()){
	}
	
	return 0;
}