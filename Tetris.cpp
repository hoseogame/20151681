#include <iostream>
#include <conio.h>
#include "TetrisGame.h"
#include "GameSchedule.h"

int T(){
	TetrisGame tg;
	std::cout << "Ű �̵�:��� �����̵�:space ����:�� ȸ��: �� " << std::endl;
	std::cout << "�����Ϸ��� �ƹ� Ű�� ��������" << std::endl;
	getch();
	system("cls");
	while (tg.Update()){
	}
	
	return 0;
}